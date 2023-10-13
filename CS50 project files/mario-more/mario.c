#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int height_pyramid=0;
    int row=1;
    int row_left;
    int row_right;
    do {
        height_pyramid=get_int("Please enter the height of the pyramid");

    } while (height_pyramid>8 || height_pyramid<1);

int height=height_pyramid;
while (height>0){
row_left=row;



while ((height_pyramid-row_left)>0){

    printf(" ");
row_left++;
}
row_left=row;
while (row_left>0){
printf("#");
row_left=row_left-1;
}

printf("  ");
row_right=row;

while (row_right>0) {
printf("#");
row_right=row_right-1;
}

//while ((row_right<height_pyramid)){

   // printf(" ");
//row_right++;
//}

printf("\n");
height=height-1;
row++;
}

}