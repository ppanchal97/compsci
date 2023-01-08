#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    char *file_name = argv[1];
    char *outfile = argv[2];

    // Open input file for reading
    FILE *inptr = fopen(file_name, "r");
    if (inptr == NULL)
    {
        fclose(inptr);
        printf("err: could not open infile");
        return 1;
    }

    // Read header into an array
    WAVHEADER wav_header;
    fread(&wav_header, sizeof(WAVHEADER), 1, inptr);
    long intptr_header = ftell(inptr);

    // Use check_format to ensure WAV format
    if (check_format(wav_header) == 1)
    {
        return 1;
    }

    // Open output file for writing
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(outptr);
        printf("err: could not open outfile");
        return 1;
    }

    // Write header to file
    fwrite(&wav_header, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    int BLOCK_SIZE = get_block_size(wav_header);

    printf("channels -> %i\n", wav_header.numChannels);

    // Write reversed audio to file
    // allocate some memory for each block
    BYTE buffer[BLOCK_SIZE];

    // start reading wav file from end to the header (44th byte)
    for (long i = wav_header.chunkSize - BLOCK_SIZE; i >= intptr_header; i -= BLOCK_SIZE)
    {
        // modify inptr to end of wav file
        fseek(inptr, i, SEEK_SET);

        // read a block at a time into the buffer
        fread(buffer, 1, BLOCK_SIZE, inptr);
        // write the buffer to the output file
        fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr);
    }

    // close all open files
    fclose(inptr);
    fclose(outptr);

    return 0;
}

int check_format(WAVHEADER header)
{
    if (header.format[0] != 87 && header.format[1] != 65 && header.format[2] != 86 && header.format[3] != 69)
    {
        // is not a WAV file
        printf("err: not a valid wav file");
        return 1;
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}