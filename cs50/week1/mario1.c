#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length;
    printf("enter square size: ");
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}