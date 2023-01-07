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

/*

1. For each red, green, blue value for surrounding 9 pixels in 3x3 grid,
multiply by the corresponding value in the Gx kernel. Then take sum of the resulting values.

2. For each red, green, blue value for surrounding 9 pixels in 3x3 grid,
multiply by the corresponding value in the Gy kernel. Then take sum of the resulting values.

3. Apply Sobel operator to Gy and Gx math.root(Gx^2 + Gy^2).

4. Round value to nearest int and cap at 255.


Edges
1. Check if going to access beyond the edges:
    - for j: if j + 1 > width +1 || j - 1 < 0;
    - for i: if i - 1 < 0 || i + 1 > height - 1;
    - if true - infer the value of that pixel as 255 255 255 (black), then multiply by the corresponding matrix value

*/
int get_sobel_value(int color, int direction, int height, int width, int i, int j, int hex, RGBTRIPLE image_copy[height][width])
{
    int kernel_sum = 0;

    int kernel[3][3];

    if (direction == 0)
    {
        // horizontal
        kernel[0][0] = -1;
        kernel[0][1] = 0;
        kernel[0][2] = 1;
        kernel[1][0] = -2;
        kernel[1][1] = 0;
        kernel[1][2] = 2;
        kernel[2][0] = -1;
        kernel[2][1] = 0;
        kernel[2][2] = 1;
    }
    else if (direction == 1)
    {
        // vertical
        kernel[0][0] = -1;
        kernel[0][1] = -2;
        kernel[0][2] = -1;
        kernel[1][0] = 0;
        kernel[1][1] = 0;
        kernel[1][2] = 0;
        kernel[2][0] = 1;
        kernel[2][1] = 2;
        kernel[2][2] = 1;
    }

    int is_edge = (i == 0 || i == height - 1) ? 1 : (j == 0 || j == width - 1) ? 1 : 0;
    

    switch (color)
    {
    case 0:
        // red
        kernel_sum += kernel[1][0] * image_copy[i][j - 1].rgbtRed;
        kernel_sum += kernel[1][1] * image_copy[i][j].rgbtRed;
        kernel_sum += kernel[1][2] * image_copy[i][j + 1].rgbtRed;
        kernel_sum += kernel[0][0] * image_copy[i - 1][j - 1].rgbtRed;
        kernel_sum += kernel[0][1] * image_copy[i - 1][j].rgbtRed;
        kernel_sum += kernel[0][2] * image_copy[i - 1][j + 1].rgbtRed;
        kernel_sum += kernel[2][0] * image_copy[i + 1][j - 1].rgbtRed;
        kernel_sum += kernel[2][1] * image_copy[i + 1][j].rgbtRed;
        kernel_sum += kernel[2][2] * image_copy[i + 1][j + 1].rgbtRed;
        break;
    case 1:
        // green
        kernel_sum += kernel[1][0] * image_copy[i][j - 1].rgbtGreen;
        kernel_sum += kernel[1][1] * image_copy[i][j].rgbtGreen;
        kernel_sum += kernel[1][2] * image_copy[i][j + 1].rgbtGreen;
        kernel_sum += kernel[0][0] * image_copy[i - 1][j - 1].rgbtGreen;
        kernel_sum += kernel[0][1] * image_copy[i - 1][j].rgbtGreen;
        kernel_sum += kernel[0][2] * image_copy[i - 1][j + 1].rgbtGreen;
        kernel_sum += kernel[2][0] * image_copy[i + 1][j - 1].rgbtGreen;
        kernel_sum += kernel[2][1] * image_copy[i + 1][j].rgbtGreen;
        kernel_sum += kernel[2][2] * image_copy[i + 1][j + 1].rgbtGreen;
        break;
    case 2:
        // blue
        kernel_sum += kernel[1][0] * image_copy[i][j - 1].rgbtBlue;
        kernel_sum += kernel[1][1] * image_copy[i][j].rgbtBlue;
        kernel_sum += kernel[1][2] * image_copy[i][j + 1].rgbtBlue;
        kernel_sum += kernel[0][0] * image_copy[i - 1][j - 1].rgbtBlue;
        kernel_sum += kernel[0][1] * image_copy[i - 1][j].rgbtBlue;
        kernel_sum += kernel[0][2] * image_copy[i - 1][j + 1].rgbtBlue;
        kernel_sum += kernel[2][0] * image_copy[i + 1][j - 1].rgbtBlue;
        kernel_sum += kernel[2][1] * image_copy[i + 1][j].rgbtBlue;
        kernel_sum += kernel[2][2] * image_copy[i + 1][j + 1].rgbtBlue;
        break;

    default:
        break;
    }

    return kernel_sum;
}

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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // for each pixel
            // get GX value for red chan
            int gx_value_red_chan = get_sobel_value(0, 0, height, width, i, j, image[i][j].rgbtRed, copy);
            // get GX value for green chan
            int gx_value_green_chan = get_sobel_value(1, 0, height, width, i, j, image[i][j].rgbtRed, copy);
            // get GX value for blue chan
            int gx_value_blue_chan = get_sobel_value(2, 0, height, width, i, j, image[i][j].rgbtRed, copy);

            // get GY value for red chan
            int gy_value_red_chan = get_sobel_value(0, 1, height, width, i, j, image[i][j].rgbtRed, copy);
            // get GY value for green chan
            int gy_value_green_chan = get_sobel_value(1, 1, height, width, i, j, image[i][j].rgbtRed, copy);
            // get GY value for blue chan
            int gy_value_blue_chan = get_sobel_value(2, 1, height, width, i, j, image[i][j].rgbtRed, copy);

            // apply sobel operator to GX and GY value for red chan, round and cap at 255
            image[i][j].rgbtRed = cap_hex_value(sqrt(gx_value_red_chan * gx_value_red_chan + gy_value_red_chan * gy_value_red_chan));
            // apply sobel operator to GX and GY value for green chan, round and cap at 255
            image[i][j].rgbtGreen = cap_hex_value(sqrt(gx_value_green_chan * gx_value_green_chan + gy_value_green_chan * gy_value_green_chan));
            // apply sobel operator to GX and GY value for blue chan, round and cap at 255
            image[i][j].rgbtBlue = cap_hex_value(sqrt(gx_value_blue_chan * gx_value_blue_chan + gy_value_blue_chan * gy_value_blue_chan));
        }
    }

    return;
}
