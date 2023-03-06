#include <stdio.h>

int collatz(int n);
void assert(int x, int y);

int main(void)
{
    // test cases
    assert(collatz(1), 0);
    assert(collatz(3), 7);
    assert(collatz(5), 5);
    assert(collatz(7), 16);
    assert(collatz(15), 17);
    assert(collatz(27), 111);
    assert(collatz(50), 24);

    return 0;
}

int collatz(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n / 2);
    }
    else {
        return 1 + collatz(3 * n + 1);
    }
}

void assert(int x, int y)
{
    if (x != y)
    {
        // assertion failed, error
        printf("FAILED: assertion failed. Expected: %i. Received:%i\n", x, y);
    }
    else {
        printf("PASS. Expected: %i. Received: %i\n", x, y);
    }
}