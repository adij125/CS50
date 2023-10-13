#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_number;
    int front_digits;
    long sum2=0;
    long sum=0;
    int total=0;
    int digit=0;
    int total2=0;
    do{
     credit_number=get_long("What is the credit card number?");
    } while (credit_number/100000000000000000!=0);



long divider=10;
long divider2=1;
while (credit_number/divider>1l){

   sum=credit_number/divider;
   divider=divider*100;
   sum=sum%(10);
    if (sum*2>9){

        total=total+((sum*2)%10l)+((sum*2)/10l);

    } else{
    total=total+sum*2;
    }



}

while (credit_number/divider2>=1){

    sum2=credit_number/divider2;
    divider2=divider2*100;
    sum2=sum2%10;
    total2=total2+sum2;

}

if(credit_number/(divider/100)>9){

front_digits=credit_number/(divider/100);

} else {

    front_digits=credit_number/(divider2/100);
}


int checker=total2+total;
printf("%li krfk",credit_number/1000000000000l);
if (checker%10==0){

    if ((front_digits==34 || front_digits==37) && credit_number/100000000000000>0){

        printf("AMEX\n");
    } else if ((front_digits==51 || front_digits==52 || front_digits==53 || front_digits==54 || front_digits==55) && credit_number/100000000000000>0){
        printf("MASTERCARD\n");

    } else if ((front_digits/10==4 && (credit_number/1000000000000000>0))|| ((credit_number/1000000000000>0)& (credit_number/10000000000000<=0))){

        printf("VISA\n");
    } else {

        printf("INVALID\n");
    }
} else {

        printf("INVALID\n");
    }


}