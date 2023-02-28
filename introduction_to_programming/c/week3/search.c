#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    const int elements = 5;

    int nums[elements] = {1, 2, 3, 4, 5};

    printf("Number: ");
    scanf("%i", &n);

    for (int i = 0; i < elements; i++)
    {
        if (nums[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}