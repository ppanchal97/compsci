#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caesar(char *plaintext, int key);
int is_valid_key(char *key);

/*
- C implementation of the simple Caesar cypher.
*/
int main(int argc, char *argv[])
{
    int key;

    if (argc != 2 || !isdigit(*argv[1]) || atoi(argv[1]) <= 0 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        key = atoi(argv[1]);
        int text_buffer_size = 1024;
        char *plaintext = malloc(text_buffer_size);
        printf("plaintext: ");
        fgets(plaintext, text_buffer_size, stdin);

        caesar(plaintext, key % 26);

        return 0;
    }
}

int is_valid_key(char *key)
{
    int is_valid = 1;

    for (int i = 0; i < strlen(key); i++)
    {
        if(!isdigit(key[i]))
        {
            is_valid = 0;
            break;
        }
    }

    return is_valid;
}

int caesar(char *plaintext, int key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int p = plaintext[i] - 65;
                int new_char = (p + key) % 26;
                printf("%c", new_char + 65);
            }
            else
            {
                int p = plaintext[i] - 97;
                int new_char = (p + key) % 26;
                printf("%c", new_char + 97);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    return 0;
}