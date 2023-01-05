#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *name = malloc(80 * sizeof(char));
    printf("What's your name?\n");
    scanf("%s", name);

    printf("hello, %s\n", name);

    free(name);

    return 0;
}