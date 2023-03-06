#include <stdio.h>

int main(void)
{
    const int length = 6;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}