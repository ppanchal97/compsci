// Saves popular dog names in a trie
// https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
} node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);
void assert(char *name, bool expectation);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return 1;
    }

    // initialize trie
    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a'; // 0 to 26
            if (cursor->children[index] == NULL)
            {

                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                // initialize new trie node
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    char *name1 = "Nala";
    char *name2 = "Zoey";
    char *name3 = "Paisley";
    char *name4 = "Hagrid";
    char *name5 = "Hagrida";
    char *name6 = "Hagride";
    char *name7 = "Ronnie";
    char *name8 = "Alien";
    char *name9 = "Hollie";
    char *name10 = "Holly";

    assert(name1, true);
    assert(name2, true);
    assert(name3, true);
    assert(name4, true);
    assert(name5, true);
    assert(name10, true);

    assert(name6, false);
    assert(name7, false);
    assert(name8, false);
    assert(name9, false);

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char *word)
{
    node *cursor = root;
    for (int i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        int index = tolower(word[i]) - 'a';
        // check if the element in the array is null
        if (cursor->children[index] == NULL)
        {
            return false;
        }
        // check if end of the word and the element marks a word
        if (i == strlen(word) - 1 &&  cursor->children[index]->is_word == true)
        {
            return true;
        }
        
        // move cursor to the children of the array
        cursor = cursor->children[index];
    }
    

    return false;
}

// Unload trie from memory
bool unload(void)
{

    // The recursive function handles all of the freeing
    unloader(root);

    return true;
}

void unloader(node *current)
{

    // Iterate over all the children to see if they point to anything and go
    // there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    // and return to the previous iteration of this function.
    free(current);
}

void assert(char *name, bool expectation)
{
    if (name == NULL)
    {
        return;
    }
    
    if (check(name) == expectation)
    {
        printf("%s - PASS\n", name);
        return;
    }
    
    printf("%s - FAIL\n", name);
    return;
}