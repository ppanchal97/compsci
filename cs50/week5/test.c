#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

FILE *inptr = NULL;

typedef struct TrieNode
{
    // The Trie Node Structure
    // Each node has N children, starting from the root
    // and a flag to check if it's a leaf node
    char data; // Storing for printing purposes only
    struct TrieNode *children[SIZE_OF_ALPHABET];
    int is_leaf;
} TrieNode;

// Trie Structure
TrieNode *root;

// Buffer for each word
char buffer[LENGTH];

// Words read in dictionary
int WORDS_READ = 0;

// Prototypes
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
TrieNode *create_trienode(char data);
void free_trienode(TrieNode *node);
TrieNode *insert_trie(char *word);
bool check(char *word);
TrieNode *make_trienode(char data);
int search_trie(TrieNode *root, char *word);

int main(int argc, const char *argv[])
{
    // Initialize root of trie
    root = make_trienode('\0');
    if (root == NULL)
    {
        return 1;
    }

    load(argv[1]);

    char *word = "we";

    if (check(word) == true)
    {
        printf("found\n");
        return 0;
    }
    else
    {
        printf("not found\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(inptr);
}

TrieNode *make_trienode(char data)
{
    // Allocate memory for a TrieNode
    TrieNode *node = (TrieNode *)calloc(1, sizeof(TrieNode));
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
        node->children[i] = NULL;
    node->is_leaf = 0;
    node->data = data;
    return node;
}

int search_trie(TrieNode *root, char *word)
{
    // Searches for word in the Trie
    TrieNode *temp = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int position = word[i] - 'a';
        if (temp->children[position] == NULL)
            return 0;
        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1)
        return 1;
    return 0;
}

bool check(char *word)
{
    printf("Searching for %s: ", word);
    if (search_trie(root, word) == 0)
    {
        printf("Not Found\n");
        return false;
    }
    else
    {
        printf("Found!\n");
        return true;
    }
}

// Read each word from the dict then load into the hash-table, returning true if successful, else false
bool load(const char *dictionary)
{
    // Allocate root of trie and initialize children
    root = make_trienode('\0');

    TrieNode *temp = root;

    // File with names
    inptr = fopen(dictionary, "r");
    if (!inptr)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Add words to the trie
    while (fscanf(inptr, "%s", buffer) == 1)
    {
        // Inserts the word onto the Trie
        // ASSUMPTION: The word only has lower case characters
        TrieNode *temp = root;

        for (int i = 0; buffer[i] != '\0'; i++)
        {
            // Get the relative position in the alphabet list
            int idx = (int)buffer[i] - 'a';
            if (temp->children[idx] == NULL)
            {
                // If the corresponding child doesn't exist,
                // simply create that child!
                temp->children[idx] = make_trienode(buffer[i]);
            }
            else
            {
                // Do nothing. The node already exists
            }
            // Go down a level, to the child referenced by idx
            // since we have a prefix match
            temp = temp->children[idx];
        }
        // At the end of the word, mark this node as the leaf node
        temp->is_leaf = 1;

        WORDS_READ++;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return WORDS_READ;
}

// Unload trie from memory
bool unload(void)
{
    fclose(inptr);
    return true;
}