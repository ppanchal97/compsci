#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The number of children for each node
// We will construct a N-ary tree and make it
// a Trie
// Since we have 26 english letters, we need
// 26 children per node
#define N 26
#define LENGTH 45

int WORDS_READ = 0;
int misspellings = 0;

typedef struct TrieNode
{
    // The Trie Node Structure
    // Each node has N children, starting from the root
    // and a flag to check if it's a leaf node
    char data; // Storing for printing purposes only
    struct TrieNode *children[N];
    int is_leaf;
} TrieNode;

TrieNode *make_trienode(char data);
void free_trienode(TrieNode *node);
TrieNode *insert_trie(TrieNode *root, char *word);
int search_trie(TrieNode *root, char *word);
void print_trie(TrieNode *root);
void print_search(TrieNode *root, char *word);
double calculate(const struct rusage *b, const struct rusage *a);
unsigned int size(void);

int main(int argc, char *argv[])
{
    // Structures for timing data
    struct rusage before, after;

    // Benchmarks
    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

    // Driver program for the Trie Data Structure Operations
    TrieNode *root = make_trienode('\0');

    // File with names
    FILE *inptr = fopen(argv[1], "r");
    if (!inptr)
    {
        printf("Error opening dictionary!\n");
        return 1;
    }

    // ========= LOAD =========
    getrusage(RUSAGE_SELF, &before);
    char buffer[45 + 1];
    // Add words to the trie
    while (fscanf(inptr, "%s", buffer) == 1)
    {
        const unsigned long word_len = strlen(buffer);
        char *word = malloc((word_len + 1) * sizeof(char));
        for (int i = 0; i < word_len; i++)
        {
            if (isalpha(buffer[i]))
            {
                word[i] = tolower(buffer[i]);
            }
            else if (ispunct(buffer[i]))
            {
                word[i] = buffer[i];
            }
            
        }
        word[word_len + 1] = '\0';
        // printf("inserting %s\n", word);
        WORDS_READ++;
        root = insert_trie(root, word);
    }

    getrusage(RUSAGE_SELF, &after);
    // Calculate time to load dictionary
    time_load = calculate(&before, &after);

    // ========= END LOAD =========

    FILE *textinptr = fopen(argv[2], "r");
    if (!textinptr)
    {
        printf("Error opening text!\n");
        return 1;
    }

    // ========= CHECK =========
    getrusage(RUSAGE_SELF, &before);

    int index = 0, words = 0;
    char word[LENGTH + 1];

    // Spell-check each word in text
    char c;
    while (fread(&c, sizeof(char), 1, textinptr))
    {
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Append character to word
            word[index] = c;
            index++;

            // Ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // Consume remainder of alphabetical string
                while (fread(&c, sizeof(char), 1, textinptr) && isalpha(c))
                    ;

                // Prepare for new word
                index = 0;
            }
        }

        // Ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // Consume remainder of alphanumeric string
            while (fread(&c, sizeof(char), 1, textinptr) && isalnum(c))
                ;

            // Prepare for new word
            index = 0;
        }

        // We must have found a whole word
        else if (index > 0)
        {
            // Terminate current word
            word[index] = '\0';

            // Update counter
            words++;

            for (int i = 0; word[i]; i++)
            {
                word[i] = tolower(word[i]);
            }

            // Check word's spelling
            // printf("checking %s\n", word);
            print_search(root, word);

            // Prepare for next word
            index = 0;
        }
    }
    getrusage(RUSAGE_SELF, &after);
    time_check += calculate(&before, &after);

    // ========= END CHECK =========

    // print_trie(root);

    // ========= SIZE =========
    getrusage(RUSAGE_SELF, &before);
    unsigned int n = size();
    getrusage(RUSAGE_SELF, &after);

    // Calculate time to determine dictionary's size
    time_size = calculate(&before, &after);

    // ========= UNLOAD =========
    getrusage(RUSAGE_SELF, &before);
    free_trienode(root);
    fclose(inptr);
    getrusage(RUSAGE_SELF, &after);

    // ========= END UNLOAD=========

    // Calculate time to determine dictionary's size
    // Calculate time to unload dictionary
    time_unload = calculate(&before, &after);

    // Report benchmarks
    printf("\nWORDS MISSPELLED:     %d\n", misspellings);
    printf("WORDS IN DICTIONARY:  %d\n", n);
    printf("WORDS IN TEXT:        %d\n", words);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN check:        %.2f\n", time_check);
    printf("TIME IN size:         %.2f\n", time_size);
    printf("TIME IN unload:       %.2f\n", time_unload);
    printf("TIME IN TOTAL:        %.2f\n\n",
           time_load + time_check + time_size + time_unload);

    // Success
    return 0;
}

TrieNode *make_trienode(char data)
{
    // Allocate memory for a TrieNode
    TrieNode *node = (TrieNode *)calloc(1, sizeof(TrieNode));
    for (int i = 0; i < N; i++)
        node->children[i] = NULL;
    node->is_leaf = 0;
    node->data = data;
    return node;
}

void free_trienode(TrieNode *node)
{
    // Free the trienode sequence
    for (int i = 0; i < N; i++)
    {
        if (node->children[i] != NULL)
        {
            free_trienode(node->children[i]);
        }
        else
        {
            continue;
        }
    }
    free(node);
}

TrieNode *insert_trie(TrieNode *root, char *word)
{
    // Inserts the word onto the Trie
    // ASSUMPTION: The word only has lower case characters
    TrieNode *temp = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        // Get the relative position in the alphabet list
        int idx = (int)word[i] - 'a';
        if (temp->children[idx] == NULL)
        {
            // If the corresponding child doesn't exist,
            // simply create that child!
            temp->children[idx] = make_trienode(word[i]);
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
    return root;
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

void print_trie(TrieNode *root)
{
    // Prints the nodes of the trie
    if (!root)
        return;
    TrieNode *temp = root;
    printf("%c -> ", temp->data);
    for (int i = 0; i < N; i++)
    {
        print_trie(temp->children[i]);
    }
}

void print_search(TrieNode *root, char *word)
{
    // printf("Searching for %s: ", word);
    if (search_trie(root, word) == 0)
    {
        // printf("Not Found\n");
        misspellings++;
    }
    // else
    // {
    //     CORRECT_SPELLED_WORDS++;
    //     // printf("Found!\n");
    // }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return WORDS_READ;
}

// Returns number of seconds between b and a
double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec))) /
                1000000.0);
    }
}
