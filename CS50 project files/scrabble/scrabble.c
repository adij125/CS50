#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i\n",score1);
    printf("%i\n",score2);
    if(score1>score2){

printf("Player 1 wins!");

} else if(score2>score1){
printf("Player 2 wins!");

} else{

    printf("Tie!");
}
}



int compute_score(string word)
{
    int length=strlen(word);
    int letter;
    int points_pos=0;
   for(int i=0; i<length; i++){
        letter=word[i];

        if(65<=letter && letter<91){


                letter=letter+32;

        }

        if (letter<65 ||(90<letter && letter<97) || letter>122){



        }
        else {
            letter=letter-97;
            points_pos=points_pos+POINTS[letter];
        }
    }

return points_pos;

}
