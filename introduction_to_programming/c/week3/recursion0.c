#include <stdio.h>

int draw_recursive(int n);
int draw_iterative(int n);

/*
- Simple C program to demonstrate interoperability of recursion and iteration.
*/
int main(void)
{
    draw_recursive(5);

    draw_iterative(5);

    return 0;
}

int draw_recursive(int n)
{
    // base case
    if (n <= 0)
    {
        printf("err: invalid input");
        return 1;
    }
    else if (n == 1)
    {
        printf("#");
        printf("\n");
    }
    else
    {
        // recursive step
        draw_recursive(n - 1);

        for (int i = 0; i < n; i++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}

int draw_iterative(int n)
{
    for (int row = 0; row < n; row++)
    {
        for (int i = 0; i < row + 1; i++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}