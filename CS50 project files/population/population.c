#include <cs50.h>
#include <stdio.h>

int main(void)
{
int start_pop=0;
int end_pop=0;
int years=0;
do {

 start_pop=get_int("What is the starting population size?");
} while ( start_pop<9);

do {
end_pop=get_int("What is the finishing population size?");

} while ( end_pop<start_pop);

while (start_pop<end_pop) {

start_pop=start_pop+start_pop/3-start_pop/4;

years++;


}

printf("Years: %i", years);
}
