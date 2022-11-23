#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length;
    do
    {
        printf("enter square size: ");
        scanf("%d", &length);
    } while (length < 10);
    
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}