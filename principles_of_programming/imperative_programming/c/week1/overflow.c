#include <stdio.h>

int main(void)
{
    int x = 2000000000;
    int y = 2000000000;
    // demonstrates overflow
    printf("total is %d\n", x + y);

    long n = 2000000000;
    long m = 2000000000;

    // demonstrates correct behaviour
    printf("total is %li\n", n + m);
}