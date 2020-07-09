#include "helpers.h"
#include <stdlib.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            double blue = image[i][j].rgbtBlue ;
            double green = image[i][j].rgbtGreen ;
            double red = image[i][j].rgbtRed ;

            double average ;
            average = (blue + green + red) / 3 ;

            image[i][j].rgbtBlue = round (average) ;
            image[i][j].rgbtGreen = round (average) ;
            image[i][j].rgbtRed = round (average) ;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            double blue = image[i][j].rgbtBlue ;
            double green = image[i][j].rgbtGreen ;
            double red = image[i][j].rgbtRed ;

            double sepiaRed, sepiaGreen, sepiaBlue ;

            sepiaRed = round((0.393 * red) + (0.769 * green) + (0.189 * blue)) ;
            sepiaGreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue)) ;
            sepiaBlue = round((0.272 * red) + (0.534 * green) + (0.131 * blue)) ;

            if (sepiaRed > 255)
            {
                sepiaRed = 255 ;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255 ;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255 ;
            }

            image[i][j].rgbtBlue = sepiaBlue ;
            image[i][j].rgbtGreen = sepiaGreen ;
            image[i][j].rgbtRed = sepiaRed ;
        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width / 2 ; j++)
        {
                RGBTRIPLE a = image[i][j] ;
                RGBTRIPLE b = image[i][(width - j - 1)] ;
                image[i][j] = b ;
                image[i][(width-j-1)] = a ;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE copyimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyimage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i+1][j].rgbtRed + copyimage[i][j+1].rgbtRed + copyimage[i+1][j+1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i+1][j].rgbtGreen + copyimage[i][j+1].rgbtGreen + copyimage[i+1][j+1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i+1][j].rgbtBlue + copyimage[i][j+1].rgbtBlue + copyimage[i+1][j+1].rgbtBlue) / 4.0);
            }
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i+1][j].rgbtRed + copyimage[i][j-1].rgbtRed + copyimage[i+1][j-1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i+1][j].rgbtGreen + copyimage[i][j-1].rgbtGreen + copyimage[i+1][j-1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i+1][j].rgbtBlue + copyimage[i][j-1].rgbtBlue + copyimage[i+1][j-1].rgbtBlue) / 4.0);
            }
            else if (i == 0)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i][j-1].rgbtRed + copyimage[i][j+1].rgbtRed + copyimage[i+1][j].rgbtRed + copyimage[i+1][j-1].rgbtRed + copyimage[i+1][j+1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i][j-1].rgbtGreen + copyimage[i][j+1].rgbtGreen + copyimage[i+1][j].rgbtGreen + copyimage[i+1][j-1].rgbtGreen + copyimage[i+1][j+1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i][j-1].rgbtBlue + copyimage[i][j+1].rgbtBlue + copyimage[i+1][j].rgbtBlue + copyimage[i+1][j-1].rgbtBlue + copyimage[i+1][j+1].rgbtBlue) / 6.0);
            }
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i-1][j].rgbtRed + copyimage[i][j+1].rgbtRed + copyimage[i-1][j+1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i-1][j].rgbtGreen + copyimage[i][j+1].rgbtGreen + copyimage[i-1][j+1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i-1][j].rgbtBlue + copyimage[i][j+1].rgbtBlue + copyimage[i-1][j+1].rgbtBlue) / 4.0);
            }
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i-1][j].rgbtRed + copyimage[i+1][j].rgbtRed + copyimage[i][j+1].rgbtRed + copyimage[i-1][j+1].rgbtRed + copyimage[i+1][j+1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i-1][j].rgbtGreen + copyimage[i+1][j].rgbtGreen + copyimage[i][j+1].rgbtGreen + copyimage[i-1][j+1].rgbtGreen + copyimage[i+1][j+1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i-1][j].rgbtBlue + copyimage[i+1][j].rgbtBlue + copyimage[i][j+1].rgbtBlue + copyimage[i-1][j+1].rgbtBlue + copyimage[i+1][j+1].rgbtBlue) / 6.0);
            }
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i-1][j].rgbtRed + copyimage[i][j-1].rgbtRed + copyimage[i-1][j-1].rgbtRed) / 4.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i-1][j].rgbtGreen + copyimage[i][j-1].rgbtGreen + copyimage[i-1][j-1].rgbtGreen) / 4.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i-1][j].rgbtBlue + copyimage[i][j-1].rgbtBlue + copyimage[i-1][j-1].rgbtBlue) / 4.0);
            }
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i][j-1].rgbtRed + copyimage[i][j+1].rgbtRed + copyimage[i-1][j].rgbtRed + copyimage[i-1][j-1].rgbtRed + copyimage[i-1][j+1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i][j-1].rgbtGreen + copyimage[i][j+1].rgbtGreen + copyimage[i-1][j].rgbtGreen + copyimage[i-1][j-1].rgbtGreen + copyimage[i-1][j+1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i][j-1].rgbtBlue + copyimage[i][j+1].rgbtBlue + copyimage[i-1][j].rgbtBlue + copyimage[i-1][j-1].rgbtBlue + copyimage[i-1][j+1].rgbtBlue) / 6.0);
            }
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i-1][j].rgbtRed + copyimage[i+1][j].rgbtRed + copyimage[i][j-1].rgbtRed + copyimage[i-1][j-1].rgbtRed + copyimage[i+1][j-1].rgbtRed) / 6.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i-1][j].rgbtGreen + copyimage[i+1][j].rgbtGreen + copyimage[i][j-1].rgbtGreen + copyimage[i-1][j-1].rgbtGreen + copyimage[i+1][j-1].rgbtGreen) / 6.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i-1][j].rgbtBlue + copyimage[i+1][j].rgbtBlue + copyimage[i][j-1].rgbtBlue + copyimage[i-1][j-1].rgbtBlue + copyimage[i+1][j-1].rgbtBlue) / 6.0);
            }
            else
            {
                image[i][j].rgbtRed = round((copyimage[i][j].rgbtRed + copyimage[i][j-1].rgbtRed + copyimage[i][j+1].rgbtRed + copyimage[i-1][j].rgbtRed + copyimage[i-1][j-1].rgbtRed + copyimage[i-1][j+1].rgbtRed + copyimage[i+1][j].rgbtRed + copyimage[i+1][j-1].rgbtRed + copyimage[i+1][j+1].rgbtRed) / 9.0);

                image[i][j].rgbtGreen = round((copyimage[i][j].rgbtGreen + copyimage[i][j-1].rgbtGreen + copyimage[i][j+1].rgbtGreen + copyimage[i-1][j].rgbtGreen + copyimage[i-1][j-1].rgbtGreen + copyimage[i-1][j+1].rgbtGreen + copyimage[i+1][j].rgbtGreen + copyimage[i+1][j-1].rgbtGreen + copyimage[i+1][j+1].rgbtGreen) / 9.0);

                image[i][j].rgbtBlue = round((copyimage[i][j].rgbtBlue + copyimage[i][j-1].rgbtBlue + copyimage[i][j+1].rgbtBlue + copyimage[i-1][j].rgbtBlue + copyimage[i-1][j-1].rgbtBlue + copyimage[i-1][j+1].rgbtBlue + copyimage[i+1][j].rgbtBlue + copyimage[i+1][j-1].rgbtBlue + copyimage[i+1][j+1].rgbtBlue) / 9.0);
            }
        }
    }

    return;

}
