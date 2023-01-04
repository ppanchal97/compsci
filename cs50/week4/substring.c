#include <stdio.h>

int strlength(char *string);
int strcompare(char *a, char *b);
int is_substring(char *string, char *substring);

int main(void)
{
    // given a string and a substring, check if substring exists in the string;
    char *string = "wasd";
    char *substring = "wasdssss";

    if (is_substring(string, substring) == 0)
    {
        printf("A substring\n");
        return 0;
    }
    else if (is_substring(string, substring) == 1)
    {
        printf("Not a substring\n");
        return 0;
    }

    printf("Error\n");
    return 1;
}

int is_substring(char *string, char *substring)
{
    if (string == NULL || substring == NULL)
    {
        return -1;
    }

    if (strlength(substring) > strlength(string))
    {
        return -1;
    }
    
    
    // iterate over string
    for (int i = 0; i < strlength(string); i++)
    {
        // if string[i] == substring[0]
        if (strcompare(&string[i], &substring[0]) == 0)
        {
            int is_substring = 0; // a substring
            int s_index = 0;

            // check next strlen(substring) chars with substring
            for (int j = i; j < i + strlength(substring); j++)
            {

                if (*(string + j) != *(substring + s_index))
                {
                    is_substring = 1;
                    break;
                }

                s_index += 1;
            }

            // if match, return true, else continue
            if (is_substring == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int strlength(char *string)
{
    if (string == NULL)
    {
        return 1;
    }

    int counter = 0;

    while (*string != '\0')
    {
        counter += 1;
        string += 1;
    }

    return counter;
}

int strcompare(char *a, char *b)
{
    for (int i = 0; i < strlength(a); i++)
    {
        if (*a + i != *b + i)
        {
            return 1;
        }
    }

    return 0;
}