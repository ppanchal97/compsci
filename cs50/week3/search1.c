#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = malloc(20);
    const int strings_memory = 20;

    printf("String: ");
    scanf("%s", s);

    char *strings[strings_memory] = {"aa", "bb", "cc", "dd", "ee"};

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(s, strings[i]) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}