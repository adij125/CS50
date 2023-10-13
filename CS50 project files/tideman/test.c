#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

int smallest=-1;
int found_loop=0;

int candidate_count=5;
// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

bool tracker(int source, int counter,int original);
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];


int pair_count = 5;
int main(void){

            pairs[0].winner = 2; pairs[0].loser = 0;
            pairs[1].winner = 4; pairs[1].loser = 1;
            pairs[2].winner = 1; pairs[2].loser = 3;
            pairs[3].winner = 3; pairs[3].loser = 4;
            pairs[4].winner = 4; pairs[4].loser = 2;


    // TODO

for(int p=0; p<pair_count; p++){
    locked[pairs[p].winner][pairs[p].loser]=true;

}
for(int i=0; i<pair_count; i++){
int counter =0;
smallest=-1;
int original=pairs[i].winner;
found_loop=0;
printf("Original:%i\n",original);
bool cycle= tracker(pairs[i].winner, counter,original);
printf("DONE\n");
}
//{

  //  } else {
    //    for(int a=0; a<pair_count; a++){
      //      locked[pairs[a].winner][pairs[a].loser]=true;
        //}
  return 0;
    }





bool tracker(int source, int counter,int original){

counter++;
for(int j=0; j<pair_count; j++){
    printf("J:%i\n",j);
    if(counter<=candidate_count){
    if(original==source && counter>1){
        printf("true\n");
        printf("count:%i\n",counter);
        return true;
    } else if(source==pairs[j].loser && locked[pairs[j].winner][pairs[j].loser]==true){

        if(j>smallest){
            smallest=j;
        printf("smallest:%i\n",smallest);
        }
       printf("cycle about to be entered");
       if(tracker(pairs[j].winner,counter,original)){
        found_loop=1;
        locked[pairs[smallest].winner][pairs[smallest].loser]=false;
            printf("Eliminated %i winner and %i loser\n",pairs[smallest].winner,pairs[smallest].loser);


            j=pair_count;
            printf("J finito %i\n",j);
       }

    }


    }


    if(found_loop==1){
        j=pair_count;
    }

}

    return false;


}