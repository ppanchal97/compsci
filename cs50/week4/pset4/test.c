#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

typedef struct
{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

int main()
{
    const int height = 4;
    const int width = 4;

    int image[height][width];

    RGBTRIPLE image_copy[height][width];

    image_copy[0][0].rgbtBlue = 12;
    image_copy[0][0].rgbtGreen = 19;
    image_copy[0][0].rgbtRed = 13;
    image_copy[0][1].rgbtBlue = 12;
    image_copy[0][1].rgbtGreen = 19;
    image_copy[0][1].rgbtRed = 133;
    image_copy[0][2].rgbtBlue = 12;
    image_copy[0][2].rgbtGreen = 219;
    image_copy[0][2].rgbtRed = 13;
    image_copy[0][3].rgbtBlue = 152;
    image_copy[0][3].rgbtGreen = 19;
    image_copy[0][3].rgbtRed = 13;

    image_copy[1][0].rgbtBlue = 132;
    image_copy[1][0].rgbtGreen = 19;
    image_copy[1][0].rgbtRed = 21;
    image_copy[1][1].rgbtBlue = 12;
    image_copy[1][1].rgbtGreen = 19;
    image_copy[1][1].rgbtRed = 153;
    image_copy[1][2].rgbtBlue = 13;
    image_copy[1][2].rgbtGreen = 113;
    image_copy[1][2].rgbtRed = 13;
    image_copy[1][3].rgbtBlue = 12;
    image_copy[1][3].rgbtGreen = 19;
    image_copy[1][3].rgbtRed = 39;

    image_copy[2][0].rgbtBlue = 12;
    image_copy[2][0].rgbtGreen = 19;
    image_copy[2][0].rgbtRed = 13;
    image_copy[2][1].rgbtBlue = 12;
    image_copy[2][1].rgbtGreen = 19;
    image_copy[2][1].rgbtRed = 57;
    image_copy[2][2].rgbtBlue = 31;
    image_copy[2][2].rgbtGreen = 19;
    image_copy[2][2].rgbtRed = 99;
    image_copy[2][3].rgbtBlue = 0;
    image_copy[2][3].rgbtGreen = 19;
    image_copy[2][3].rgbtRed = 13;

    image_copy[3][0].rgbtBlue = 12;
    image_copy[3][0].rgbtGreen = 19;
    image_copy[3][0].rgbtRed = 18;
    image_copy[3][1].rgbtBlue = 12;
    image_copy[3][1].rgbtGreen = 19;
    image_copy[3][1].rgbtRed = 15;
    image_copy[3][2].rgbtBlue = 12;
    image_copy[3][2].rgbtGreen = 19;
    image_copy[3][2].rgbtRed = 13;
    image_copy[3][3].rgbtBlue = 192;
    image_copy[3][3].rgbtGreen = 191;
    image_copy[3][3].rgbtRed = 17;

    int i = 2;
    int j = 3;

    int avg = 0;

    int count = 0;

    avg += image_copy[i][j].rgbtBlue;
    avg += image_copy[i][j].rgbtGreen;
    avg += image_copy[i][j].rgbtRed;
    
    count += 3;

    if (j != 0)
    {
        avg += image_copy[i][j - 1].rgbtBlue;
        avg += image_copy[i][j - 1].rgbtGreen;
        avg += image_copy[i][j - 1].rgbtRed;

        count += 3;
    }
    if (j != width - 1)
    {
        avg += image_copy[i][j + 1].rgbtBlue;
        avg += image_copy[i][j + 1].rgbtGreen;
        avg += image_copy[i][j + 1].rgbtRed;
        
        count += 3;
    }
    if (i != 0)
    {
        avg += image_copy[i - 1][j].rgbtBlue;
        avg += image_copy[i - 1][j].rgbtGreen;
        avg += image_copy[i - 1][j].rgbtRed;

        count += 3;
    }
    if (i != 0 && j != 0)
    {
        avg += image_copy[i - 1][j - 1].rgbtBlue;
        avg += image_copy[i - 1][j - 1].rgbtGreen;
        avg += image_copy[i - 1][j - 1].rgbtRed;

        count += 3;
    }
    if (i != 0 && j != width - 1)
    {
        avg += image_copy[i - 1][j + 1].rgbtBlue;
        avg += image_copy[i - 1][j + 1].rgbtGreen;
        avg += image_copy[i - 1][j + 1].rgbtRed;

        count += 3;
    }
    if (i != height - 1)
    {
        avg += image_copy[i + 1][j].rgbtBlue;
        avg += image_copy[i + 1][j].rgbtGreen;
        avg += image_copy[i + 1][j].rgbtRed;

        count += 3;
    }
    if (i != height - 1 && j != width - 1)
    {
        avg += image_copy[i + 1][j + 1].rgbtBlue;
        avg += image_copy[i + 1][j + 1].rgbtGreen;
        avg += image_copy[i + 1][j + 1].rgbtRed;

        count += 3;
    }
    if (i != height - 1 && j != 0)
    {
        avg += image_copy[i + 1][j - 1].rgbtBlue;
        avg += image_copy[i + 1][j - 1].rgbtRed;
        avg += image_copy[i + 1][j - 1].rgbtGreen;

        count += 3;
    }

    printf("%i\n", avg / count);
}