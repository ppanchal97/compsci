#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substitution(char *plaintext, char *key);
int is_valid_key(char *key);

/*
- C implementation of a simple substitution cypher.
*/
int main(int argc, char *argv[])
{
    char *key = argv[1];

    if (argc != 2 || strlen(argv[1]) != 26 || !is_valid_key(key))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int text_buffer_size = 1024;
        char *plaintext = malloc(text_buffer_size);
        printf("plaintext: ");
        fgets(plaintext, text_buffer_size, stdin);

        substitution(plaintext, key);

        return 0;
    }
}

int substitution(char *plaintext, char *key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            int p;
            if (isupper(plaintext[i]))
            {
                p = plaintext[i] - 65;
                printf("%c", toupper(key[p]));
            }
            else
            {
                p = plaintext[i] - 97;
                printf("%c", tolower(key[p]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

    return 0;
}

int is_valid_key(char *key)
{
    int is_valid = 1;

    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            is_valid = 0;
            break;
        }
        else
        {

            for (int j = i; j < strlen(key) - 1; j++)
            {
                if (key[i] == key[j + 1])
                {
                    is_valid = 0;
                }
            }
        }
    }

    return is_valid;
}