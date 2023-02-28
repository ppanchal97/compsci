#include <stdio.h>

/*
 String indexing using the 's[i]' syntax is syntactical sugar for incrementing
 the memory address's location accessed through a pointer.
*/
int main(void)
{
    char *s = "HI!";
    
    // incrementing memory addresses
    printf("%c\n", *s + 0);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));

    printf("\n");

    // syntactic sugar
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);
}