#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int count_letters(string text);

int count_words(string text);

int count_sentences(string text);
int main(void)
{

string text=get_string("Text:");

//printf("%s\n", text);

float letter=count_letters(text);
float words=count_words(text);
float sentence=count_sentences(text);

//printf("letter %f\n words %f\n sentence %f\n",letter,words,sentence);

float L=(letter/words)*100.00;
float S=(sentence/words)*100.00;

//printf("L %f\n S %f\n", L, S);
float index = 0.0588 * L - 0.296 * S - 15.8;

if(index>16){

    printf("Grade 16+\n");
} else if(index<1){

    printf("Before Grade 1\n");
} else {

    printf("Grade %1.0f\n",index);

}
}

int count_letters(string text){

int size=strlen(text);

int letter;
int count=0;
for (int i=0; i<size; i++){
    letter=text[i];
    if (letter>64 && letter<123){

        count++;
    }


}
    return count;
}

int count_words(string text){

int size=strlen(text);
int space=0;
int letter;
int count=0;
for (int i=0; i<size; i++){
    letter=text[i];
    if (letter==32){
        count++;
    }

}

return count+1;

}

int count_sentences(string text){

int size=strlen(text);
int space=0;
int letter;
int count=0;
for (int i=0; i<size; i++){
    letter=text[i];
    if (letter==33 || letter==46 || letter==63){
        count++;
    }

}

return count;

}