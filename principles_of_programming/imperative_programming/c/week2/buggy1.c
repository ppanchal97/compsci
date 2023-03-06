#include <stdio.h>

int main(void)
{
    int i;

    do
    {
        printf("Negative Number: ");
        scanf("%i", &i);
    } while (i >= 0);
}