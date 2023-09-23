#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue != 255 && image[i][j].rgbtGreen != 255 && image[i][j].rgbtRed != 255)
            {
                image[i][j].rgbtBlue = 37;
                image[i][j].rgbtGreen = 146;
                image[i][j].rgbtRed = 255;
            }
        }
    }
}





