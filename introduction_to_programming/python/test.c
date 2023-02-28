#include <stdio.h>

int main(void)
{
    int nums[5] = {12, 234, 971, 0, 1};

    // bubble sort
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int holder = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = holder;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%i ", nums[i]);
    }

    // binary search
    int left = 0;
    int right = 5 - 1;
    int target = 1123;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (nums[middle] == target)
        {
            printf("found\n");
            return 0;
        }
        else if (nums[middle] > target)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    printf("not found\n");
    return -1;
}