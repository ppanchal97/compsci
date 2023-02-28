#include <stdio.h>

void recursive_pyramid(int n);

int main(void)
{
    recursive_pyramid(3);
}


void recursive_pyramid(int n)
{
    if (n == 0)
    {
        return;
    }
    else if (n == 1)
    {
        printf("#\n");
        return;
    }
    
    recursive_pyramid(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    
    printf("\n");
}