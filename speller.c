// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next ;
} node ;

// Number of buckets in hash table
const unsigned int N = 16900 + 1;

// Hash table
node *table[N];

int number_of_words = 0 ;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char temporary_word[LENGTH + 1] ;

    for (int m = 0 ; word[m] != '\0' ; m ++)
    {

        temporary_word[m] = tolower(word[m]) ;
    }

    unsigned long hash_value = hash(temporary_word) ;

    node* list = table[hash_value] ;

    while (list != NULL)
    {
        if (list->word == word)
        {
            return true ;
        }
        else
        {
            list = list->next ;
        }
    }
    return false ;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash = N;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *fr = fopen(dictionary, "r") ;
    if (fr == NULL)
    {
        return false ;
    }

    char c_word[LENGTH + 1] ;

    while (fscanf (fr, "%s", c_word) != EOF)
    {
        number_of_words++ ;

        node *space = malloc(sizeof(struct node)) ;
        if (space == NULL)
        {
            return false ;
        }

        strcpy(space->word, c_word) ;
        int hash_value = hash(space->word) ;

        if (table[hash_value] == NULL)
        {
            table[hash_value] = space ;
            space->next = NULL ;
        }
        else
        {
            space->next = table[hash_value] ;
            table[hash_value] = space ;
        }
    }

    free(fr) ;
    fclose(fr) ;

    return true ;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return number_of_words ;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0 ; i < N ; i++)
    {
        node* list = table[i] ;

        while(list != NULL)
        {
            node* pointer = list ;
            list = list->next ;
            free(pointer) ;

            if (pointer != NULL)
            {
                return false ;
            }
        }
        free(list) ;

        if(list != NULL)
        {
            return false ;
        }
    }

    return true ;
}
