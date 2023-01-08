#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int is_valid_fourth_byte(int n);
int recover(char *file_name);

int main(int argc, char *argv[])
{
    char *file_name = argv[1];

    return recover(file_name);
}

int is_valid_fourth_byte(int n)
{
    if (n >= 224 && n <= 239)
    {
        return 1;
    }

    return 0;
}

int recover(char *file_name)
{
    int BLOCK_SIZE = 512;

    // open memory card
    FILE *inptr = fopen(file_name, "r");
    if (inptr == NULL)
    {
        fclose(inptr);
        printf("err: could not open file");
        return EXIT_FAILURE;
    }

    BYTE buffer[BLOCK_SIZE];

    int jpeg_counter = 0;
    char *outfile = malloc(80 * sizeof(char));

    int found_jpeg = 0;

    FILE *outptr = NULL;

    // read 512 blocks into buffer until end of card
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {

        // check if first 4 bytes equal to a jpeg header
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && is_valid_fourth_byte(buffer[3]))
        {

            if (jpeg_counter >= 0 && found_jpeg == 1)
            {
                jpeg_counter++;
                fclose(outptr);
            }

            found_jpeg = 1;

            // create file_name
            sprintf(outfile, "%03i.jpg", jpeg_counter);

            // open output file
            outptr = fopen(outfile, "w");
            if (outptr == NULL)
            {
                fclose(inptr);
                printf("err: could not create %s.\n", outfile);
                return EXIT_FAILURE;
            }

            // write to file
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
        }
        else
        {
            if (found_jpeg == 1)
            {
                // keep writing current block
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
            }
        }
    }

    // close all remaining files
    free(outfile);
    fclose(outptr);
    fclose(inptr);

    if (found_jpeg)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}