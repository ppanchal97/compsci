#include <stdio.h>

int main(void)
{
    char a, b;

    a = -128;

    printf("%d\n", a);

    b = a - 1; // Underflow occurs here

    printf("%d\n", b);
}