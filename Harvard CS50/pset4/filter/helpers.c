#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            BYTE *bc = &image[i][j].rgbtBlue;
            BYTE *gc= &image[i][j].rgbtGreen;
            BYTE *rc = &image[i][j].rgbtRed;

            //printf("%i\n", *bc);
            //printf("%i\n", *gc);
            //printf("%i\n", *rc);

            float b = image[i][j].rgbtBlue;
            float g = image[i][j].rgbtGreen;
            float r = image[i][j].rgbtRed;

            float average = round((b+g+r)/3);
            *bc = average;
            *gc = average;
            *rc = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{   for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            BYTE *bc = &image[i][j].rgbtBlue;
            BYTE *gc= &image[i][j].rgbtGreen;
            BYTE *rc = &image[i][j].rgbtRed;

            int originalBlue = image[i][j].rgbtBlue;
            int originalGreen = image[i][j].rgbtGreen;
            int originalRed = image[i][j].rgbtRed;

            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            *bc = sepiaBlue;
            *gc = sepiaGreen;
            *rc = sepiaRed;


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   for (int i=0; i<height; i++)
    {
        for (int j=0; j<width/2; j++)
        {
            int x = width-1-(j);
            BYTE *bc1 = &image[i][j].rgbtBlue;
            BYTE *gc1 = &image[i][j].rgbtGreen;
            BYTE *rc1 = &image[i][j].rgbtRed;

            BYTE *bc2 = &image[i][x].rgbtBlue;
            BYTE *gc2 = &image[i][x].rgbtGreen;
            BYTE *rc2 = &image[i][x].rgbtRed;

            int tb1 = image[i][j].rgbtBlue;
            int tg1 = image[i][j].rgbtGreen;
            int tr1 = image[i][j].rgbtRed;

            int tb2 = image[i][x].rgbtBlue;
            int tg2 = image[i][x].rgbtGreen;
            int tr2 = image[i][x].rgbtRed;

            *bc1 = tb2;
            *gc1 = tg2;
            *rc1 = tr2;

            *bc2 = tb1;
            *gc2 = tg1;
            *rc2 = tr1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
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
                int red = 0;
                int green = 0;
                int blue = 0;
                float counter = 0;

                // 5
                red += copy[i][j].rgbtRed;
                green += copy[i][j].rgbtGreen;
                blue += copy[i][j].rgbtBlue;
                counter++;

                //1
                if (i - 1 > -1 && j - 1 > -1)
                {
                    red += copy[i - 1][j-1].rgbtRed;
                    green += copy[i - 1][j-1].rgbtGreen;
                    blue += copy[i - 1][j-1].rgbtBlue;
                    counter++;
                }
                // 2
                if (i - 1 > -1)
                {
                    red += copy[i - 1][j].rgbtRed;
                    green += copy[i - 1][j].rgbtGreen;
                    blue += copy[i - 1][j].rgbtBlue;
                    counter++;
                }
                // 3
                if (i - 1 > -1 && j + 1 < width)
                {
                    red += copy[i - 1][j + 1].rgbtRed;
                    green += copy[i - 1][j + 1].rgbtGreen;
                    blue += copy[i - 1][j + 1].rgbtBlue;
                    counter++;
                }
                // 4
                if (j - 1 > -1)
                {
                    red += copy[i][j - 1].rgbtRed;
                    green += copy[i][j - 1].rgbtGreen;
                    blue += copy[i][j - 1].rgbtBlue;
                    counter++;
                }
                // 6
                if (j + 1 < width)
                {
                    red += copy[i][j + 1].rgbtRed;
                    green += copy[i][j + 1].rgbtGreen;
                    blue += copy[i][j + 1].rgbtBlue;
                    counter++;
                }
                // 7
                if (i + 1 < height && j - 1 > -1)
                {
                    red += copy[i + 1][j - 1].rgbtRed;
                    green += copy[i + 1][j - 1].rgbtGreen;
                    blue += copy[i + 1][j - 1].rgbtBlue;
                    counter++;
                }
                // 8
                if (i + 1 < height)
                {
                    red += copy[i + 1][j].rgbtRed;
                    green += copy[i + 1][j].rgbtGreen;
                    blue += copy[i + 1][j].rgbtBlue;
                    counter++;
                }
                // 9
                if (i + 1 < height && j + 1 < width)
                {
                    red += copy[i + 1][j + 1].rgbtRed;
                    green += copy[i + 1][j + 1].rgbtGreen;
                    blue += copy[i + 1][j + 1].rgbtBlue;
                    counter++;
                }

                image[i][j].rgbtRed = round(red/counter);
                image[i][j].rgbtGreen = round(green/counter);
                image[i][j].rgbtBlue = round(blue/counter);
            }
}
return;
}