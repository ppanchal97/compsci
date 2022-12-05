#include <stdio.h>

int binary_search(int arr[], int target, int arr_len);

int main(void)
{
    int nums[7] = {9, 20, 5, 6, 15, 123, 0};

    binary_search(nums, 20, 7);

    return 0;
}

int binary_search(int arr[], int target, int arr_len)
{
    int middle = (arr_len - 1) / 2;

    if (arr_len == 0)
    {
        printf("err: no elements to search");
        return 1;
    }

    if (arr[middle] == target)
    {
        printf("%i found at index %i\n", target, middle);
        return 0;
    } 
    else if (target > arr[middle])
    {
        // look right
    }
    

    return 0;
}