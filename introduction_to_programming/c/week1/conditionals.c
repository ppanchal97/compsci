#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;

    // conditionals and default returns. Note that program exits when a branch evaluates to true
    if (a > b)
    {
        printf("a is greater than \n");
    }
    else if (a == 10 || a == 15)
    {
        printf("a is 10 or 15\n");
    }
    else
    {
        printf("b is greater than a\n");
    }
}
