#include <ctype.h>
#include <stdio.h>
#include <string.h>

int is_valid_key(char *key);

int main(void)
{
    char *key = "ABCA";
    printf("%i\n", is_valid_key(key));
}

int is_valid_key(char *key)
{
    int is_valid = 1;

    // check for nums
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("digit detected\n");
            is_valid = 0;
            break;
        }
    }

    // check for duplicates
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i; j < strlen(key) - 1; j++)
        {
            if (key[i] == key[j + 1])
            {
                is_valid = 0;
            }
            
        }
        
    }

    return is_valid;
}