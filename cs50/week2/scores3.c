#include <stdio.h>
#include <stdlib.h>

const int ARRAY_LEN = 3;

int average_array(int array[]);

int main(void)
{
    int scores[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("Enter score: ");
        scanf("%i", &scores[i]);
    }

    printf("The average score is: %i\n", average_array(scores));
}

// This function could be designed better by accepting length as an argument rather than referring to a global variable
int average_array(int array[])
{
    int array_sum = 0;
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        array_sum += array[i];
    }
    return array_sum / ARRAY_LEN;
}