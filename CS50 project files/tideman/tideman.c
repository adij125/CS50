#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

int smallest=-1;
int found_loop=0;
// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;


// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void sort(int list[],int size,int sorted[]);

bool tracker(int source, int counter, int original);
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}


bool tracker(int source, int counter,int original){

    counter++;
    for(int j = 0; j < pair_count; j++){

    if(counter<=candidate_count){
    if(original==source && counter>1){

        return true;
    } else if(source==pairs[j].loser && locked[pairs[j].winner][pairs[j].loser]==true){

        if(j>smallest){
            smallest=j;
        }

       if(tracker(pairs[j].winner,counter,original)){
        found_loop=1;
        locked[pairs[smallest].winner][pairs[smallest].loser]=false;



            j=pair_count;

       }




    }

}
    if(found_loop==1){
        j=pair_count;
    }

}

    return false;


}
// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
   for(int i=0; i<candidate_count; i++){

    if(strcmp(candidates[i],name)==0){

        ranks[rank]=i;

        return true;
    }

   }


    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int highest_preference=0;
    int next_preference=0;

        for(int i=0; i<candidate_count-1; i++){

        for(int p=0; p<candidate_count-1-i; p++){

            highest_preference=ranks[i];

            next_preference=ranks[p+1+i];


            preferences[highest_preference][next_preference]=preferences[highest_preference][next_preference]+1;
       //printf("%i\n", preferences[highest_preference][next_preference]);
        }

        }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    bool repeat;
    for(int i=0; i<candidate_count; i++){

        for(int j=0; j<candidate_count; j++){

            if(preferences[i][j]>preferences[j][i]){
                 repeat=false;
                for(int q=0; q<=pair_count; q++){
                    if(pairs[q].winner==i && pairs[q].loser==j){
                        repeat=true;
                    }
                }
                if(repeat==false){
                pairs[pair_count].winner=i;
                pairs[pair_count].loser=j;
                pair_count++;

                }
            } else if(preferences[i][j]<preferences[j][i]){

                     repeat =   false;
                    for(int z=0; z<=pair_count; z++){
                    if (pairs[z].winner == j && pairs[z].loser == i){
                        repeat = true;
                    }
                }
                if (repeat == false){
                pairs[pair_count].winner=j;
                pairs[pair_count].loser=i;
                pair_count++;

                }
            }
        }
    }
    return;
}







// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO




    int bop=1;
    int temp;
    while(bop != 0){
    bop=0;
             for(int i=0; i<pair_count-1; i++){



        if(preferences[pairs[i].winner][pairs[i].loser]<preferences[pairs[i+1].winner][pairs[i+1].loser]){

            temp=pairs[i].winner;
            pairs[i].winner=pairs[i+1].winner;
            pairs[i+1].winner=temp;
            temp=pairs[i].loser;
            pairs[i].loser=pairs[i+1].loser;
            pairs[i+1].loser=temp;

            bop++;
        }


    }

}
return;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO

            for(int p=0; p<pair_count; p++){
    locked[pairs[p].winner][pairs[p].loser]=true;

}
            for(int i=0; i<pair_count; i++){
        int counter = 0;
    smallest=-1;
    int original=pairs[i].winner;
    found_loop = 0;
    bool cycle = tracker(pairs[i].winner, counter,original);

}

  return;
    }



// Print the winner of the election
void print_winner(void)
{
    // TODO

    int max=0;
    string winning_candidate;
    for(int j=0; j<candidate_count; j++){
    int won=0;
    for(int i=0; i<candidate_count; i++){

            if(locked[i][j]!=true){

                won++;
    }


    }
        if(won==candidate_count){
        printf("%s\n",candidates[j]);
    return;
    }


    }



}