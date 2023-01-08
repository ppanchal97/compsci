#include <stdio.h>

int sum(int nums[], int sum);

int main(int argc, char const *argv[])
{
    int nums[4] = {1, 2, 3, 9};
    int s = 15;

    int found = sum(nums, s);

    if (found)
    {
        printf("found\n");
    }
    else
    {
        printf("not found\n");
    }

    return 0;
}

int sum(int nums[], int sum)
{
    int is_found = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (nums[i] + nums[j] == sum)
            {
                is_found = 1;
            }
        }
    }

    return is_found;
}