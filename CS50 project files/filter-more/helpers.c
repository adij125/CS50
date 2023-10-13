#include "helpers.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
typedef struct {

    int Red;
    int Green;
    int Blue;
}

temporary;
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int Blue;
    int Green;
    int Red;
    float Ave;
    int Average=0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            Blue= image[i][j].rgbtBlue;
            Green=image[i][j].rgbtGreen;
            Red=image[i][j].rgbtRed;
            Ave= (Blue+Green+Red)/3.00;

            int temp=Ave*10;
            if(temp%10>=5){

                Average=Ave+1;
            } else {

                Average=Ave;
            }

            image[i][j].rgbtBlue=Average;
            image[i][j].rgbtGreen=Average;
            image[i][j].rgbtRed=Average;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

int temp_blue;
int temp_green;
int temp_red;
    for(int i=0; i<height; i++){

            for(int j=0; j<(width/2); j++){
            temp_blue= image[i][j].rgbtBlue;
            temp_green=image[i][j].rgbtGreen;
            temp_red=image[i][j].rgbtRed;

            image[i][j].rgbtBlue=image[i][width-j-1].rgbtBlue;
            image[i][j].rgbtGreen=image[i][width-j-1].rgbtGreen;
            image[i][j].rgbtRed=image[i][width-j-1].rgbtRed;

            image[i][width-j-1].rgbtBlue=temp_blue;
            image[i][width-j-1].rgbtGreen=temp_green;
            image[i][width-j-1].rgbtRed=temp_red;

            }


    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float pixel_Green=0.00;
    float pixel_Red=0.00;
    float pixel_Blue=0.00;
    float bop;
    int ave_Blue;
    int ave_Red;
    int ave_Green;

    temporary copy[height][width];
    for(int i=0; i<height; i++){

            for(int j=0; j<width; j++){
                pixel_Blue=image[i][j].rgbtBlue;
                pixel_Red=image[i][j].rgbtRed;
                pixel_Green=image[i][j].rgbtGreen;
                bop=1;
                  if(i-1>=0){

                    if(j+1<width){

                    pixel_Blue=pixel_Blue+image[i-1][j+1].rgbtBlue;
                    pixel_Red=pixel_Red+image[i-1][j+1].rgbtRed;
                    pixel_Green=pixel_Green+image[i-1][j+1].rgbtGreen;

                    bop++;
                    }

                    if(j-1>=0){

                    pixel_Blue=pixel_Blue+image[i-1][j-1].rgbtBlue;
                    pixel_Red=pixel_Red+image[i-1][j-1].rgbtRed;
                    pixel_Green=pixel_Green+image[i-1][j-1].rgbtGreen;

                    bop++;

                    }

                    pixel_Blue=pixel_Blue+image[i-1][j].rgbtBlue;
                    pixel_Red=pixel_Red+image[i-1][j].rgbtRed;
                    pixel_Green=pixel_Green+image[i-1][j].rgbtGreen;

                    bop++;
                }

                   if(i+1<height){

                    if(j+1<width){

                    pixel_Blue=pixel_Blue+image[i+1][j+1].rgbtBlue;
                    pixel_Red=pixel_Red+image[i+1][j+1].rgbtRed;
                    pixel_Green=pixel_Green+image[i+1][j+1].rgbtGreen;

                    bop++;

                    }


                    if(j-1>=0){

                    pixel_Blue=pixel_Blue+image[i+1][j-1].rgbtBlue;
                    pixel_Red=pixel_Red+image[i+1][j-1].rgbtRed;
                    pixel_Green=pixel_Green+image[i+1][j-1].rgbtGreen;

                    bop++;

                    }
                    pixel_Blue=pixel_Blue+image[i+1][j].rgbtBlue;
                    pixel_Red=pixel_Red+image[i+1][j].rgbtRed;
                    pixel_Green=pixel_Green+image[i+1][j].rgbtGreen;

                    bop++;


                   }

                    if(j+1<width){

                    pixel_Blue=pixel_Blue+image[i][j+1].rgbtBlue;
                    pixel_Red=pixel_Red+image[i][j+1].rgbtRed;
                    pixel_Green=pixel_Green+image[i][j+1].rgbtGreen;

                    bop++;

                    }

                    if(j-1>=0){

                    pixel_Blue=pixel_Blue+image[i][j-1].rgbtBlue;
                    pixel_Red=pixel_Red+image[i][j-1].rgbtRed;
                    pixel_Green=pixel_Green+image[i][j-1].rgbtGreen;

                    bop++;

                    }

                pixel_Blue=pixel_Blue/bop;
                pixel_Green=pixel_Green/bop;
                pixel_Red=pixel_Red/bop;

                int temp=pixel_Blue*10;
                if((temp)%10>=5){

                    copy[i][j].Blue=pixel_Blue+1;

                } else {
                    copy[i][j].Blue=pixel_Blue;
                }


                temp=pixel_Red*10;
                if((temp)%10>=5){

                    copy[i][j].Red=pixel_Red+1;
                } else{

                    copy[i][j].Red=pixel_Red;
                }

                temp=pixel_Green*10;
                if((temp)%10>=5){

                    copy[i][j].Green=pixel_Green+1;
                } else {

                    copy[i][j].Green=pixel_Green;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{


    int Gx[3][3];
    int Gy[3][3];

    temporary copy[height][width];




    double temp;
    double pixel_Blue_x;
    double pixel_Red_x;
    double pixel_Green_x;

    double pixel_Blue_y;
    double pixel_Red_y;
    double pixel_Green_y;

    Gx[0][0]=-1;
    Gx[0][1]=0;
    Gx[0][2]=1;
    Gx[1][0]=2*Gx[0][0];
    Gx[1][1]=2*Gx[0][1];
    Gx[1][2]=2*Gx[0][2];
    Gx[2][0]=Gx[0][0];
    Gx[2][1]=Gx[0][1];
    Gx[2][2]=Gx[0][2];


    Gy[0][0]=-1;
    Gy[0][1]=-2;
    Gy[0][2]=-1;
    Gy[1][0]=0;
    Gy[1][1]=0;
    Gy[1][2]=0;
    Gy[2][0]=1;
    Gy[2][1]=2;
    Gy[2][2]=1;



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

                    pixel_Blue_x=pixel_Blue_x+(image[i-1][j+1].rgbtBlue)*Gx[0][2];
                    pixel_Red_x=pixel_Red_x+(image[i-1][j+1].rgbtRed)*Gx[0][2];
                    pixel_Green_x= pixel_Green_x+(image[i-1][j+1].rgbtGreen)*Gx[0][2];

                    pixel_Blue_y=pixel_Blue_y+(image[i-1][j+1].rgbtBlue)*Gy[0][2];
                    pixel_Red_y=pixel_Red_y+(image[i-1][j+1].rgbtRed)*Gy[0][2];
                    pixel_Green_y= pixel_Green_y+(image[i-1][j+1].rgbtGreen)*Gy[0][2];
                    }


                    if(j-1>=0){

                    pixel_Blue_x=pixel_Blue_x+(image[i-1][j-1].rgbtBlue)*Gx[0][0];
                    pixel_Red_x=pixel_Red_x+(image[i-1][j-1].rgbtRed)*Gx[0][0];
                    pixel_Green_x= pixel_Green_x+(image[i-1][j-1].rgbtGreen)*Gx[0][0];

                    pixel_Blue_y=pixel_Blue_y+(image[i-1][j-1].rgbtBlue)*Gy[0][0];
                    pixel_Red_y=pixel_Red_y+(image[i-1][j-1].rgbtRed)*Gy[0][0];
                    pixel_Green_y= pixel_Green_y+(image[i-1][j-1].rgbtGreen)*Gy[0][0];

                    }

                    pixel_Blue_y=pixel_Blue_y+(image[i-1][j].rgbtBlue)*Gy[0][1];
                    pixel_Red_y=pixel_Red_y+(image[i-1][j].rgbtRed)*Gy[0][1];
                    pixel_Green_y= pixel_Green_y+(image[i-1][j].rgbtGreen)*Gy[0][1];

                }

                if(i+1<height){

                    if(j+1<width){
                    pixel_Blue_x=pixel_Blue_x+(image[i+1][j+1].rgbtBlue)*Gx[2][2];
                    pixel_Red_x=pixel_Red_x+(image[i+1][j+1].rgbtRed)*Gx[2][2];
                    pixel_Green_x= pixel_Green_x+(image[i+1][j+1].rgbtGreen)*Gx[2][2];

                    pixel_Blue_y=pixel_Blue_y+(image[i+1][j+1].rgbtBlue)*Gy[2][2];
                    pixel_Red_y=pixel_Red_y+(image[i+1][j+1].rgbtRed)*Gy[2][2];
                    pixel_Green_y= pixel_Green_y+(image[i+1][j+1].rgbtGreen)*Gy[2][2];

                    }

                    if(j-1>=0){

                    pixel_Blue_x=pixel_Blue_x+(image[i+1][j-1].rgbtBlue)*Gx[2][0];
                    pixel_Red_x=pixel_Red_x+(image[i+1][j-1].rgbtRed)*Gx[2][0];
                    pixel_Green_x= pixel_Green_x+(image[i+1][j-1].rgbtGreen)*Gx[2][0];

                    pixel_Blue_y=pixel_Blue_y+(image[i+1][j-1].rgbtBlue)*Gy[2][0];
                    pixel_Red_y=pixel_Red_y+(image[i+1][j-1].rgbtRed)*Gy[2][0];
                    pixel_Green_y= pixel_Green_y+(image[i+1][j-1].rgbtGreen)*Gy[2][0];

                    }

                    pixel_Blue_y=pixel_Blue_y+(image[i+1][j].rgbtBlue)*Gy[2][1];
                    pixel_Red_y=pixel_Red_y+(image[i+1][j].rgbtRed)*Gy[2][1];
                    pixel_Green_y= pixel_Green_y+(image[i+1][j].rgbtGreen)*Gy[2][1];

                }


                    if(j-1>=0){

                    pixel_Blue_x=pixel_Blue_x+(image[i][j-1].rgbtBlue)*Gx[1][0];
                    pixel_Red_x=pixel_Red_x+(image[i][j-1].rgbtRed)*Gx[1][0];
                    pixel_Green_x= pixel_Green_x+(image[i][j-1].rgbtGreen)*Gx[1][0];

                    }

                    if(j+1<width){


                    pixel_Blue_x=pixel_Blue_x+(image[i][j+1].rgbtBlue)*Gx[1][2];
                    pixel_Red_x=pixel_Red_x+(image[i][j+1].rgbtRed)*Gx[1][2];
                    pixel_Green_x= pixel_Green_x+(image[i][j+1].rgbtGreen)*Gx[1][2];


                    }

                    temp=sqrt((pixel_Red_x*pixel_Red_x)+(pixel_Red_y*pixel_Red_y));

                    if(round(temp)>255){
                    copy[i][j].Red=255;


                    } else {

                        copy[i][j].Red=round(temp);
                    }


                     temp=sqrt((pixel_Blue_x*pixel_Blue_x)+(pixel_Blue_y*pixel_Blue_y));

                     if(round(temp)>255){
                     copy[i][j].Blue=255;
                     } else{

                        copy[i][j].Blue=round(temp);
                     }
                     temp=sqrt((pixel_Green_x*pixel_Green_x)+(pixel_Green_y*pixel_Green_y));

                     if(round(temp)>255){
                     copy[i][j].Green=255;
                     } else{

                        copy[i][j].Green=round(temp);
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



  //  printf("first %i ",image[0][1].rgbtBlue);
    return;
}


