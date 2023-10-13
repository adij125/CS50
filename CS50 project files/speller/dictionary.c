// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char *dictionary="dictionary/small.txt";
    FILE *dicptr=fopen(dictionary,"r");

    char temp[strlen(word)-1];
    while(fread(&temp,1,1,dicptr)==1){
        if(strcmp(temp,word)==0){

            printf("%s\n",temp);
            fclose(dicptr);
            return true;
        }

    }

    fclose(dicptr);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    int temp=0;
    if(strlen(word)>1){
         temp=tolower(word[1])-'a';
    }

    int word0=tolower(word[0])-'a';
    return (word0*26)+temp;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    int index=0;
    char *word_load;
    while(fread(word_load,1,1,dictionary)==1){

      index=hash(word_load);
      if(table[index]->word)
      table[index]->word=word_load;
      node *next=malloc(sizeof(node));
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
