#include <stdio.h>

int min(int a, int b);
int max(int a, int b);

int main()
{
    const int LEFT_SIZE = 5;
    const int RIGHT_SIZE = 4;

    int left_nums[LEFT_SIZE] = {1, 9, 45, 92, 101};
    int right_nums[RIGHT_SIZE] = {0, 213, 12, 4};

    int lesser_array_size = min(LEFT_SIZE, RIGHT_SIZE);

    int reordered_nums[LEFT_SIZE + RIGHT_SIZE];

    // iterate over arrays
    int idx = 0;
    while (idx < lesser_array_size)
    {    
        // compare and copy
        if (left_nums[idx] < right_nums[idx])
        {
            reordered_nums[idx] = left_nums[idx];
        }
        reordered_nums[idx] = right_nums[idx];
        idx++;
    }

    // copy all remaining
    for (int i = idx; i < max(LEFT_SIZE, RIGHT_SIZE) - 1; i++)
    {
        /* code */
    }
    
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int max(int a, int b)
{
    return (a < b) ? b : a;
}