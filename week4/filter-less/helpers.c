#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int greyscale;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            greyscale = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = greyscale;
            image[i][j].rgbtGreen = greyscale;
            image[i][j].rgbtRed = greyscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE sepia[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int orginalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = fmin(255, (int) ((0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * orginalBlue) + 0.5));
            image[i][j].rgbtGreen =
                fmin(255, (int) ((0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * orginalBlue) + 0.5));
            image[i][j].rgbtRed = fmin(255, (int) ((0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * orginalBlue) + 0.5));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary image array to store the blurred values
    RGBTRIPLE temp[height][width];

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the sum of color components and pixel count
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            // Loop through neighboring pixels (3x3 grid)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di; // Neighbor's row index
                    int nj = j + dj; // Neighbor's column index

                    // Check if the neighbor is within the image bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += image[ni][nj].rgbtRed;
                        sumGreen += image[ni][nj].rgbtGreen;
                        sumBlue += image[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color values and apply to temp array
            temp[i][j].rgbtRed = round((float) sumRed / count);
            temp[i][j].rgbtGreen = round((float) sumGreen / count);
            temp[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }

    // Copy the blurred values from temp array back to the original image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
