#include <stdio.h>
#include <stdlib.h>

// copy a list into a larger list and append an integer
int main(int argc, char const *argv[])
{
    int *list = malloc(3 * sizeof(int));
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("list %i: %i\n", i, list[i]);
    }

    // extend list
    int *tmp = malloc(4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        *(tmp + i) = *(list + i);
    }
    

    *(tmp + 3) = 4;

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("list %i: %i\n", i, list[i]);
    }

    free(tmp);

    return 0;
}
