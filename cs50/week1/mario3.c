#include <stdio.h>
#include <stdlib.h>

// function signatures
int get_size(void);
void print_blocks(int length);

int main(void)
{
    int n;

    do
    {
        n = get_size();
    } while (n < 10);

    print_blocks(n);
}

// function definitions
int get_size(void)
{
    int length;
    printf("enter square size: ");
    scanf("%d", &length);
    return length;
}

void print_blocks(int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}