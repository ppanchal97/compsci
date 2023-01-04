#include <stdio.h>

int recursive_sum(int n);
int iterative_sum(int n);

int main(void)
{
    // iterative implementation
    printf("%i\n", iterative_sum(5));

    // recursive implementation
    printf("%i\n", recursive_sum(5));

    return 0;
}

// f(n) = n + f(n-1)
int recursive_sum(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    
    // recursive case
    return n + recursive_sum(n - 1);
}

int iterative_sum(int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        counter += i + 1;    
    }

    return counter;
}