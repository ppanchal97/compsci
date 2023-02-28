#include <stdio.h>

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

int get_sepia_pixel_hex(int new_hex)
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
            image[i][j].rgbtBlue = get_sepia_pixel_hex(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            image[i][j].rgbtGreen = get_sepia_pixel_hex(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            image[i][j].rgbtRed = get_sepia_pixel_hex(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
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

BLURPIXEL get_box_blur_value(int height, int width, RGBTRIPLE image_copy[height][width], int i, int j)
{

    int red_avg = 0;
    int blue_avg = 0;
    int green_avg = 0;

    int count = 0;

    blue_avg += image_copy[i][j].rgbtBlue;
    green_avg += image_copy[i][j].rgbtGreen;
    red_avg += image_copy[i][j].rgbtRed;

    count += 1;

    if (j != 0)
    {
        blue_avg += image_copy[i][j - 1].rgbtBlue;
        green_avg += image_copy[i][j - 1].rgbtGreen;
        red_avg += image_copy[i][j - 1].rgbtRed;

        count += 1;
    }
    if (j != width - 1)
    {
        blue_avg += image_copy[i][j + 1].rgbtBlue;
        green_avg += image_copy[i][j + 1].rgbtGreen;
        red_avg += image_copy[i][j + 1].rgbtRed;

        count += 1;
    }
    if (i != 0)
    {
        blue_avg += image_copy[i - 1][j].rgbtBlue;
        green_avg += image_copy[i - 1][j].rgbtGreen;
        red_avg += image_copy[i - 1][j].rgbtRed;

        count += 1;
    }
    if (i != 0 && j != 0)
    {
        blue_avg += image_copy[i - 1][j - 1].rgbtBlue;
        green_avg += image_copy[i - 1][j - 1].rgbtGreen;
        red_avg += image_copy[i - 1][j - 1].rgbtRed;

        count += 1;
    }
    if (i != 0 && j != width - 1)
    {
        blue_avg += image_copy[i - 1][j + 1].rgbtBlue;
        green_avg += image_copy[i - 1][j + 1].rgbtGreen;
        red_avg += image_copy[i - 1][j + 1].rgbtRed;

        count += 1;
    }
    if (i != height - 1)
    {
        blue_avg += image_copy[i + 1][j].rgbtBlue;
        green_avg += image_copy[i + 1][j].rgbtGreen;
        red_avg += image_copy[i + 1][j].rgbtRed;

        count += 1;
    }
    if (i != height - 1 && j != width - 1)
    {
        blue_avg += image_copy[i + 1][j + 1].rgbtBlue;
        green_avg += image_copy[i + 1][j + 1].rgbtGreen;
        red_avg += image_copy[i + 1][j + 1].rgbtRed;

        count += 1;
    }
    if (i != height - 1 && j != 0)
    {
        blue_avg += image_copy[i + 1][j - 1].rgbtBlue;
        green_avg += image_copy[i + 1][j - 1].rgbtGreen;
        red_avg += image_copy[i + 1][j - 1].rgbtRed;

        count += 1;
    }

    BLURPIXEL b;
    b.rgbtBlue = blue_avg / count;
    b.rgbtGreen = green_avg / count;
    b.rgbtRed = red_avg / count;

    return b;
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

    // iterate over the copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // for each pixel, get the box blur value from the copy
            BLURPIXEL b = get_box_blur_value(height, width, copy, i, j);
            // write that blur average to the pixel of the original image
            image[i][j].rgbtRed = b.rgbtRed;
            image[i][j].rgbtBlue = b.rgbtBlue;
            image[i][j].rgbtGreen = b.rgbtGreen;
        }
    }

    return;
}