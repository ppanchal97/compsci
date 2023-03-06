#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linear_search(int size, char chars[size], char target);

int main(void)
{
    char chars[5];
    
    chars[0] = 'a';
    chars[1] = 'b';
    chars[2] = 'c';
    chars[3] = 'd';
    chars[4] = 'e';

    // take input from user
    char input_char;

    input_char = fgetc(stdin);
    if (ferror(stdin))
    {
        printf("err: %s\n", strerror(errno));
        return -1;
    }

    clearerr(stdin);

    // search
    if (linear_search(5, chars, input_char) == 1)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }

    return 0;
}

int linear_search(int size, char chars[size], char target)
{
    if (size == 0 || chars == NULL)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        if (chars[i] == target)
        {
            return 1;
        }
    }

    return 0;
}