#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // for and while loops are interchangeable

    // int i 'gets' 0 - convention of describing how i is initialized to 0
    // for loop approach
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }

    int counter = 0;

     for (int i = 0; i < 10; i++)
    {
        counter += i * i;
    }
    printf("final value of counter is: %d\n", counter);

    // while loop approach through subtraction
    int count = 10;

    while (count > 0)
    {
        printf("turn %d\n", count);
        count--;
    }

    // while loop approach through addition
    count = 0;
    while (count < 10)
    {
        printf("turn %d\n", count);
        count++;
    }

    // forever
    while (true)
    {
        printf("meow\n");
        break;
    }
}