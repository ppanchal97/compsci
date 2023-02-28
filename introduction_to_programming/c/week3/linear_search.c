#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[4] = {1, 2, 3, 4};
    int target = 3;

    for (int i = 0; i < 4; i++)
    {
        if (nums[i] == target)
        {
            printf("%i was found on index %i\n", target, i);
            return 0;
        }
    }

    printf("Not found");
    return 1;
}