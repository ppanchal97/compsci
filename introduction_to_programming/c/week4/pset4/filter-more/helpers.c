#include <stdio.h>
#include <math.h>

#include "helpers.h"

typedef struct
{
    int rgbtRed;
    int rgbtBlue;
    int rgbtGreen;

} BLURPIXEL;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over each row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get average of the 3 pixels, then apply to each pixel
            const int avg_value = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            image[i][j].rgbtBlue = avg_value;
            image[i][j].rgbtGreen = avg_value;
            image[i][j].rgbtRed = avg_value;
        }
    }

    return;
}

int cap_hex_value(int new_hex)
{
    if (new_hex > 255)
    {
        return 255;
    }

    return new_hex;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over each row
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // get new value for a pixel using the algorithm, then apply to each pixel
            image[i][j].rgbtBlue = cap_hex_value(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            image[i][j].rgbtGreen = cap_hex_value(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            image[i][j].rgbtRed = cap_hex_value(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over each row
    for (int i = 0; i < height; i++)
    {
        // reverse each row
        for (int j = 0; j < width / 2; j++)
        {
            // store opposite pixel's values in a holder var
            int holderRed = image[i][width - 1 - j].rgbtRed;
            int holderGreen = image[i][width - 1 - j].rgbtGreen;
            int holderBlue = image[i][width - 1 - j].rgbtBlue;

            // modify opposite pixel's values using current pixel
            image[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed;
            image[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue;

            // modify current pixel's values using holder
            image[i][j].rgbtRed = holderRed;
            image[i][j].rgbtGreen = holderGreen;
            image[i][j].rgbtBlue = holderBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the image, but do not modify it
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    /*
    for each row
    for each col
        set count to 0
        for every neighboring pixel within the radius m in the x direction
            for every neighboring pixel within the radius m in the y direction
                 add the color to the total
                 count++
        final_color = total/count
        set pixel(current x, current y, final_color)

    */

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int count = 0;
            int col_coords[3] = {col - 1, col, col + 1};
            int row_coords[3] = {row - 1, row, row + 1};

            float red_count = 0;
            float green_count = 0;
            float blue_count = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int current_row = row_coords[r];
                    int current_col = col_coords[c];

                    if (current_row >= 0 && current_row < height && current_col >= 0 && current_col < width)
                    {
                        // valid pixel to use
                        RGBTRIPLE p = image[current_row][current_col];
                        red_count += p.rgbtRed;
                        green_count += p.rgbtGreen;
                        blue_count += p.rgbtBlue;
                        count++;
                    }
                }
            }

            // set blur value of pixel
            copy[row][col].rgbtRed = round(red_count / count);
            copy[row][col].rgbtGreen = round(green_count / count);
            copy[row][col].rgbtBlue = round(blue_count / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

int GX[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}};

int GY[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}};

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy of the image, but do not modify it
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int col_coords[3] = {col - 1, col, col + 1};
            int row_coords[3] = {row - 1, row, row + 1};

            float GXR = 0;
            float GXG = 0;
            float GXB = 0;
            float GYR = 0;
            float GYG = 0;
            float GYB = 0;

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int current_row = row_coords[r];
                    int current_col = col_coords[c];

                    if (current_row >= 0 && current_row < height && current_col >= 0 && current_col < width)
                    {
                        // found valid pixel to use
                        RGBTRIPLE p = image[current_row][current_col];

                        // compute Gx for r chan
                        GXR += GX[r][c] * p.rgbtRed;

                        // compute Gx for g chan
                        GXG += GX[r][c] * p.rgbtGreen;

                        // compute Gx for b chan
                        GXB += GX[r][c] * p.rgbtBlue;

                        // compute Gy for r chan
                        GYR += GY[r][c] * p.rgbtRed;

                        // compute Gy for g chan
                        GYG += GY[r][c] * p.rgbtGreen;

                        // compute Gy for b chan
                        GYB += GY[r][c] * p.rgbtBlue;
                    }
                }
            }

            // set edge value of original pixel
            copy[row][col].rgbtRed = cap_hex_value(sqrt(GXR * GXR + GYR * GYR));
            copy[row][col].rgbtGreen = cap_hex_value(sqrt(GXG * GXG + GYG * GYG));
            copy[row][col].rgbtBlue = cap_hex_value(sqrt(GXB * GXB + GYB * GYB));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}
