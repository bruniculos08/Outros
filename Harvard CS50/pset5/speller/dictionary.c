// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

//hash function from http://en.wikipedia.org/wiki/Hash_function#Hashing_variable-length_data

//put by me

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;




//put by me

int countwords;

unsigned int hash(const char *word);
bool check(const char *word);


// Number of buckets in hash table
const unsigned int N = 1000000;



// Hash table
node *table[N];




// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char lower_case_word[strlen(word)+1];
    for (int i = 0; i < strlen(word)+1; i++)
    {
        if (word[0] != '\'')
        {
        lower_case_word[i] = tolower(word[i]);
        }
        else
        {
        lower_case_word[i] = tolower(word[i+1]);
        }
    }
    lower_case_word[strlen(word)+1] = '\0';
    node *cursor = table[hash(lower_case_word)];

    while (cursor != NULL)
    {
        if (strcasecmp((cursor->word), lower_case_word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}




// Hashes word to a number //unsigned
unsigned int hash(const char *word) //take the bucket number for a word, in this case the number decides it by the first letter
{
    // initialize index to 0
   // int index = 0;


    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;

        // comma case
        else
            n = 27;

        hash = ((hash << 3) + n) % N;
    }
    return hash;

    //return index-97;
    //return index;
}



//const char word[LENGTH + 1];
char word[LENGTH + 1];

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");


    if (file == NULL)
    {

        printf("Could not Load\n");
        unload();
        //fclose(file);
        return false;

    }


    //for (fscanf(file, "%s", word); fgetc(file) != EOF ; fscanf(file, "%s", word))
    while (fscanf(file, "%s", word) != EOF)
    {

        node *n = malloc(sizeof(node)); //prepare space to new node


        //n->word =  NULL   //malloc(strlen(word));     //prepare space to the word


        strcpy(n->word, word); //copy word to the node


        n->next = NULL; // set the pointer to the next node like null


        int i = hash(word); // take the namber of the bucket (table) to this word by the first letter

        if (table[i] == NULL) // if the bucket is null, it will be the pointer to the note
        {

            table[i] = n;

        }

        else  // if the bucket isn't null the next will be the actual pointer bucket and this will be the point to this node
        {

            n->next = table[i];
            table[i] = n;

        }


        countwords++;

    }

    fclose(file);
    return true;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //TODO
    return countwords;

}



// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i=0; i<1000000; i++)
    {
        //node *cursor;

        //cursor = table[i];

        while(table[i] != NULL)
        {

            node *tmp = table[i];
            table[i] = table[i]->next;
            free(tmp);

        }

       free(table[i]);

    }

    for (int i=0; i<1000000; i++)
    {

      if (table[i]!=NULL)
      {

        return false;

      }

    }
    // TODO
    return true;
}
