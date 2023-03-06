// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

FILE *inptr = NULL;

const unsigned int N = 50000;

// Hash table (array of pointers to linked list head nodes)
node *table[N];

// Words read in dictionary
int WORDS_READ = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char holder[LENGTH + 1];
    for (int i = 0; i < LENGTH + 1; i++)
    {
        holder[i] = '\0';
    }

    for (int i = 0; i < strlen(word); i++)
    {
        holder[i] = tolower(word[i]);
    }

    // generate hash
    unsigned int index = hash(holder);

    // point to the LL at the index
    node *head = table[index];

    // traverse linked list present at hash
    while (head != NULL)
    {
        // if word is present, return true
        if (strcmp(head->word, holder) == 0)
        {
            return true;
        }
        head = head->next;
    }

    return false;
}

// Hashes word to a number using the DJB2 algorithm
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % N;
}

// Read each word from the dict then load into the hash-table, returning true if successful, else false
bool load(const char *dictionary)
{
    // fopen
    inptr = fopen(dictionary, "r");

    // read each word in the dictionary
    char word[LENGTH + 1];
    while (fgets(word, sizeof(word), inptr) != NULL)
    {
        if (word[0] == '\n')
        {
            break;
        }

        // create and populate node
        node *n = malloc(sizeof(node));

        char valid_str[strlen(word)];

        int j = 0;
        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] != '\t' && word[i] != '\0' && word[i] != '\n' && word[i] != '\r')
            {
                valid_str[i] = tolower(word[i]);
                j++;
            }
        }

        valid_str[j] = '\0';

        strcpy(n->word, valid_str);
        n->next = NULL;

        // obtain hash value for the linked list
        unsigned int index = hash(word);

        // insert into the linked list that is determined by the hash function
        n->next = table[index];
        table[index] = n;
        WORDS_READ++;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return WORDS_READ;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *list = table[i];

        while (list != NULL)
        {
            node *tmp = list->next;
            free(list);
            list = tmp;
        }
    }

    fclose(inptr);

    return true;
}
