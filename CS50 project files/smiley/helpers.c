#include "helpers.h"
#include  "stdio.h"
void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for(int i=0; i<height; i++){

        for(int j=0; j<width; j++){
            if(image[i][j].rgbtBlue==0){

                image[i][j].rgbtBlue=0xCC;
                image[i][j].rgbtGreen=0;
                image[i][j].rgbtRed=0;
            }

     //   printf("%i BLUE\n", *image[i]);
     //   printf("%#x Green\n", image[i][j].rgbtGreen);
     //   printf("%#x RED\n", image[i][j].rgbtRed);
        }
    }

}
