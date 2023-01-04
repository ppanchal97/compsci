#include <stdio.h>

int main(void)
{
    int n = 10;
    
    // a pointer variables stores the memory address of some other variable. '&' syntax means memory address.
    int *ptr = &n;

    // %p is the format code to print an address with printf. And we only need to use the name of the variable, p, after we’ve declared it.
    printf("%p\n", &n);

    printf("%p\n", ptr);

    // dereference (reading and modifying value at particular memory address)
    printf("initial: %i\n", *ptr);
    *ptr = 50;
    printf("modified: %i\n", *ptr);
}