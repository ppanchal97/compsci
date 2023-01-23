#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        printf("err: could not allocate memory");
        return 1;
    }
    
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("list %i: %i\n", i, list[i]);
    }

    // copy old list automatically using realloc()
    int *tmp = realloc(list, 4 * sizeof(int));
    list = tmp;

    tmp[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("list %i: %i\n", i, list[i]);
    }

    free(tmp);

    return 0;
}
