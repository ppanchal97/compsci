#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // user input for number of rows in steps
    int height;

    do
    {
        printf("Height: ");
        scanf("%i", &height);

    }

    while (height < 1 || height > 8);

    // start loop
    for (int row = 0; row < height; row++)
    {
        // print spaces
        for (int j = 0; j < height - row - 1; j++)
        {
            printf(" ");
        }

        // print hashes
        for (int k = 0; k < row + 1; k++)
        {
            printf("#");
        }

        // print double space
        printf("  ");

        // print hashes
        for (int l = 0; l < row + 1; l++)
        {
            printf("#");
        }

        // print new line
        printf("\n");
    }
    // exit
    return 0;
}