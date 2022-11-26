#include <stdio.h>

int bubble_sort(int nums[], int arr_len);

const int NUMS_LENGTH = 7;

int main(void)
{
    int nums[NUMS_LENGTH] = {20, 8, 5, 30, 9, 4, 1};
    for (int i = 0; i < NUMS_LENGTH; i++)
    {
        printf("%i ", nums[i]);
    }
    printf("\n");
    bubble_sort(nums, NUMS_LENGTH);

    return 0;
}

int bubble_sort(int nums[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        // terminates at 1 position before the end to avoid comparing last element with one out of the array
        // ..preventing a segfault.
        for (int j = 0; j < arr_len - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                // swap
                int holder = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = holder;
            }
        }
        for (int i = 0; i < arr_len; i++)
        {
            printf("%i ", nums[i]);
        }
        printf("\n");
    }

    return 0;
}