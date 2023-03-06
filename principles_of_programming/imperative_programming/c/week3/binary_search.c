#include <stdio.h>

void bubble_sort(int size, int nums[size]);
int binary_search(int size, int nums[size], int target);

int main(void)
{
    int nums[10] = {1, 423, 45, 123, 65, 123, 65, 324, 86, 79};

    // binary search
    // sort the array
    bubble_sort(10, nums);
    printf("%i\n", binary_search(10, nums, 45));

    return 0;
}

void bubble_sort(int size, int nums[size])
{
    if (nums == NULL || size == 0)
    {
        return;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                // swap
                int holder = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = holder;
            }
        }
    }

    return;
}

// implementation assumes that the array passed to the function is sorted in ascending order
int binary_search(int size, int nums[size], int target)
{
    // calculate right
    int right = size - 1;
    // calculate left
    int left = 0;
    // while index left < index right
    while (left <= right)
    {
        // calculate middle
        int middle = (right + left) / 2;
        // if middle == target return found;
        if (nums[middle] == target)
        {
            return 0;
        }
        // else if middle < target
        else if (nums[middle] < target)
        {
            // left = middle + 1
            left = middle + 1;
        }
        else
        {
            // middle > target
            // right = middle - 1;
            right = middle - 1;
        }
    }
    // return not found;
    return 1;
}