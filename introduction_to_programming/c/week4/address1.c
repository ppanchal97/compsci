#include <stdio.h>

// CS50 implementation of mapping string data type to char *
typedef char *string;

/*
 Program prints memory addresses of characters in a string to
 demonstrate contiguous nature of arrays.
 
 exemplar output:
 0x1001c4f9e
 0x1001c4f9f
 0x1001c4fa0
 0x1001c4fa1
 0x1001c4fa2
 0x1001c4fa3
 0x1001c4fa4
 0x1001c4fa5
 0x1001c4fa6
 0x1001c4fa7
 0x1001c4fa8
 0x1001c4fa9
 0x1001c4faa
*/
int main(void)
{
    string message = "Hello, World!";

    // address of first character in the string variable message
    for (int i = 0; i < 1000000000000000; i++)
    {
        printf("%c is stored at %p\n", message[i], &message[i]);
    }
}