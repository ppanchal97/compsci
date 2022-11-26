#include <stdio.h>

int selection_sort(int nums[], int arr_len);

const int NUMS_LENGTH = 8;

/*
- C implementation of the selection sort algorithm.
*/
int main(void)
{
    int nums[NUMS_LENGTH] = {10, 11, 90, 21, 29, 2, 1, 0};

    selection_sort(nums, NUMS_LENGTH);

    return 0;
}

int selection_sort(int nums[], int arr_len)
{
    // selection sort;
    for (int i = 0; i < arr_len; i++)
    {
        int current_min = nums[i];
        int min_position = i;
        // find minimum value
        for (int j = i; j < arr_len; j++)
        {
            if (nums[j] < current_min)
            {
                current_min = nums[j];
                min_position = j;
            }
        }
        // swap current position's value with the minimum value
        int holder = nums[min_position];
        nums[min_position] = nums[i];
        nums[i] = current_min;
        printf("%i ", nums[i]);
    }

    printf("\n");
    return 0;
}