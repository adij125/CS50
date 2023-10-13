#include "helpers.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int Red;
    int Green;
    int Blue;
}

temporary;

void edges(int height, int width, RGBTRIPLE image[height][width]);

int main(void){


RGBTRIPLE grid[3][3];

for(int p=0; p<3; p++){
for(int i=0; i<3; i++){


    grid[i][p].rgbtBlue=i;
    grid[i][p].rgbtGreen=i;
    grid[i][p].rgbtRed=i;


}
}

    edges(3,3, grid);

    for(int p=0; p<3; p++){
for(int i=0; i<3; i++){

    printf("Grid %i, pos i %i pos p %i\n",grid[i][p].rgbtBlue,i,p);



}
}

}







void edges(int height, int width, RGBTRIPLE image[height][width])
{

    temporary Gx[3][3];
    temporary Gy[3][3];

    temporary copy[height][width];


    float temp;
    int pixel_Blue_x;
    int pixel_Red_x;
    int pixel_Green_x;

    int pixel_Blue_y;
    int pixel_Red_y;
    int pixel_Green_y;

    Gx[0][0].Red=-1;
    Gx[0][1].Red=0;
    Gx[0][2].Red=1;
    Gx[1][0].Red=2*Gx[0][0].Red;
    Gx[1][1].Red=2*Gx[0][1].Red;
    Gx[1][2].Red=2*Gx[0][2].Red;
    Gx[2][0].Red=Gx[0][0].Red;
    Gx[2][1].Red=Gx[0][1].Red;
    Gx[2][2].Red=Gx[0][2].Red;


    Gy[0][0].Red=-1;
    Gy[0][1].Red=-2;
    Gy[0][2].Red=-1;
    Gy[1][0].Red=0;
    Gy[1][1].Red=0;
    Gy[1][2].Red=0;
    Gy[2][0].Red=1;
    Gy[2][1].Red=2;
    Gy[2][2].Red=1;



            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
            pixel_Blue_x=0;
            pixel_Red_x=0;
            pixel_Green_x=0;

            pixel_Blue_y=0;
            pixel_Green_y=0;
            pixel_Red_y=0;
                if(i-1>=0){

                    if(j+1<width){

                    pixel_Blue_x=pixel_Blue_x+(image[i-1][j+1].rgbtBlue)*Gx[0][2].Blue;
                    pixel_Red_x=pixel_Red_x+(image[i-1][j+1].rgbtRed)*Gx[0][2].Red;
                    pixel_Green_x= pixel_Green_x+(image[i-1][j+1].rgbtGreen)*Gx[0][2].Green;

                    pixel_Blue_y=pixel_Blue_y+(image[i-1][j+1].rgbtBlue)*Gy[0][2].Blue;
                    pixel_Red_y=pixel_Red_y+(image[i-1][j+1].rgbtRed)*Gy[0][2].Red;
                    pixel_Green_y= pixel_Green_y+(image[i-1][j+1].rgbtGreen)*Gy[0][2].Green;
                    }


                    if(j-1>=0){

                    pixel_Blue_x=pixel_Blue_x+(image[i-1][j-1].rgbtBlue)*Gx[0][0].Blue;
                    pixel_Red_x=pixel_Red_x+(image[i-1][j-1].rgbtRed)*Gx[0][0].Red;
                    pixel_Green_x= pixel_Green_x+(image[i-1][j-1].rgbtGreen)*Gx[0][0].Green;

                    pixel_Blue_y=pixel_Blue_y+(image[i-1][j-1].rgbtBlue)*Gy[0][0].Blue;
                    pixel_Red_y=pixel_Red_y+(image[i-1][j-1].rgbtRed)*Gy[0][0].Red;
                    pixel_Green_y= pixel_Green_y+(image[i-1][j-1].rgbtGreen)*Gy[0][0].Green;

                 }

                    pixel_Blue_y=pixel_Blue_y+(image[i-1][j].rgbtBlue)*Gy[0][1].Blue;
                    pixel_Red_y=pixel_Red_y+(image[i-1][j].rgbtRed)*Gy[0][1].Red;
                    pixel_Green_y= pixel_Green_y+(image[i-1][j].rgbtGreen)*Gy[0][1].Green;

                }

                    if(i+1<height){

                    if(j+1<width){
                    pixel_Blue_x=pixel_Blue_x+(image[i+1][j+1].rgbtBlue)*Gx[2][2].Blue;
                    pixel_Red_x=pixel_Red_x+(image[i+1][j+1].rgbtRed)*Gx[2][2].Red;
                    pixel_Green_x= pixel_Green_x+(image[i+1][j+1].rgbtGreen)*Gx[2][2].Green;

                    pixel_Blue_y=pixel_Blue_y+(image[i+1][j+1].rgbtBlue)*Gy[2][2].Blue;
                    pixel_Red_y=pixel_Red_y+(image[i+1][j+1].rgbtRed)*Gy[2][2].Red;
                    pixel_Green_y= pixel_Green_y+(image[i+1][j+1].rgbtGreen)*Gy[2][2].Green;

                    }

                    if(j-1>=0){

                    pixel_Blue_x=pixel_Blue_x+(image[i+1][j-1].rgbtBlue)*Gx[2][0].Blue;
                    pixel_Red_x=pixel_Red_x+(image[i+1][j-1].rgbtRed)*Gx[2][0].Red;
                    pixel_Green_x= pixel_Green_x+(image[i+1][j-1].rgbtGreen)*Gx[2][0].Green;

                    pixel_Blue_y=pixel_Blue_y+(image[i+1][j-1].rgbtBlue)*Gy[2][0].Blue;
                    pixel_Red_y=pixel_Red_y+(image[i+1][j-1].rgbtRed)*Gy[2][0].Red;
                    pixel_Green_y= pixel_Green_y+(image[i+1][j-1].rgbtGreen)*Gy[2][0].Green;

                    }

                    pixel_Blue_y=pixel_Blue_y+(image[i+1][j].rgbtBlue)*Gy[2][1].Blue;
                    pixel_Red_y=pixel_Red_y+(image[i+1][j].rgbtRed)*Gy[2][1].Red;
                    pixel_Green_y= pixel_Green_y+(image[i+1][j].rgbtGreen)*Gy[2][1].Green;

                }


                    if(j-1>=0){

                    pixel_Blue_x=pixel_Blue_x+(image[i][j-1].rgbtBlue)*Gx[1][0].Blue;
                    pixel_Red_x=pixel_Red_x+(image[i][j-1].rgbtRed)*Gx[1][0].Red;
                    pixel_Green_x= pixel_Green_x+(image[i][j-1].rgbtGreen)*Gx[1][0].Green;

                    }

                    if(j+1<width){


                    pixel_Blue_x=pixel_Blue_x+(image[i][j+1].rgbtBlue)*Gx[1][2].Blue;
                    pixel_Red_x=pixel_Red_x+(image[i][j+1].rgbtRed)*Gx[1][2].Red;
                    pixel_Green_x= pixel_Green_x+(image[i][j+1].rgbtGreen)*Gx[1][2].Green;


                    }

                    temp=sqrt((pixel_Red_x*pixel_Red_x)+(pixel_Red_y*pixel_Red_y));

                    int temp2=temp*10;
                    if(temp2%10>=5){

                        copy[i][j].Red=temp+1;
                    } else {

                        copy[i][j].Red=temp;

                    }

                     temp=sqrt((pixel_Blue_x*pixel_Blue_x)+(pixel_Blue_y*pixel_Blue_y));

                     temp2=temp*10;
                     if(temp2%10>=5){

                        copy[i][j].Blue=temp+1;
                     } else {

                        copy[i][j].Blue=temp;
                     }

                     temp=sqrt((pixel_Green_x*pixel_Green_x)+(pixel_Green_y*pixel_Green_y));

                     temp2=temp*10;
                     if(temp2%10>=5){

                        copy[i][j].Green=temp+1;
                     } else {

                        copy[i][j].Green=temp;
                     }

                }
            }


    for(int p=0; p<height; p++){

        for(int q=0; q<width; q++){

            image[p][q].rgbtRed=copy[p][q].Red;
            image[p][q].rgbtBlue=copy[p][q].Blue;
            image[p][q].rgbtGreen=copy[p][q].Green;
        }
    }

    return;
}








void edges(int height, int width, RGBTRIPLE image[height][width])
{


    temporary Gx[3][3];
    temporary Gy[3][3];

    temporary copy[height][width];



    double temp;
    double pixel_Blue_x;
    double pixel_Red_x;
    double pixel_Green_x;

    double pixel_Blue_y;
    double pixel_Red_y;
    double pixel_Green_y;

    Gx[0][0].Red=-1;
    Gx[0][1].Red=0;
    Gx[0][2].Red=1;
    Gx[1][0].Red=2*Gx[0][0].Red;
    Gx[1][1].Red=2*Gx[0][1].Red;
    Gx[1][2].Red=2*Gx[0][2].Red;
    Gx[2][0].Red=Gx[0][0].Red;
    Gx[2][1].Red=Gx[0][1].Red;
    Gx[2][2].Red=Gx[0][2].Red;


    Gy[0][0].Red=-1;
    Gy[0][1].Red=-2;
    Gy[0][2].Red=-1;
    Gy[1][0].Red=0;
    Gy[1][1].Red=0;
    Gy[1][2].Red=0;
    Gy[2][0].Red=1;
    Gy[2][1].Red=2;
    Gy[2][2].Red=1;



            for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
            pixel_Blue_x=0;
            pixel_Red_x=0;
            pixel_Green_x=0;

            pixel_Blue_y=0;
            pixel_Green_y=0;
            pixel_Red_y=0;


           int row=0;
           for(int a=i-1; a<=i+1; a++){

            int column=0;
            for(int b=j-1; b<=j+1; b++){

            if(b>=0 && b<width && a>=0 && a<height){

                pixel_Blue_x+=image[a][b].rgbtBlue*Gx[row][column].Red;
                pixel_Red_x+=image[a][b].rgbtRed*Gx[row][column].Red;
                pixel_Green_x+=image[a][b].rgbtGreen*Gx[row][column].Red;

                pixel_Blue_y+=image[a][b].rgbtBlue*Gy[row][column].Red;
                pixel_Red_y+=image[a][b].rgbtRed*Gy[row][column].Red;
                pixel_Green_y+=image[a][b].rgbtGreen*Gy[row][column].Red;


            }

            column++;
           }
            row++;
           }
                    temp=sqrt((pixel_Red_x*pixel_Red_x)+(pixel_Red_y*pixel_Red_y));

                    copy[i][j].Red=round(temp);

                     temp=sqrt((pixel_Blue_x*pixel_Blue_x)+(pixel_Blue_y*pixel_Blue_y));

                     copy[i][j].Blue=round(temp);

                     temp=sqrt((pixel_Green_x*pixel_Green_x)+(pixel_Green_y*pixel_Green_y));

                     copy[i][j].Green=round(temp);


                }
            }


    for(int p=0; p<height; p++){

        for(int q=0; q<width; q++){

            image[p][q].rgbtRed=copy[p][q].Red;
            image[p][q].rgbtBlue=copy[p][q].Blue;
            image[p][q].rgbtGreen=copy[p][q].Green;
        }
    }

  //  printf("first %i ",image[0][1].rgbtBlue);
    return;
}




















