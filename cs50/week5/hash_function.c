#include <stdio.h>
#include <stdlib.h>

const signed int CAPACITY = 50000; // Size of the HashTable.

// deliberately poorly designed hash function
unsigned long hash_function(char *str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

int main(void)
{
    // demonstrate hash collision - same address for different data
    char *str1 = "Hel";
    char *str2 = "Cau";
    printf("%ld\n", hash_function(str1));
    printf("%ld\n", hash_function(str2));

    return 0;
}