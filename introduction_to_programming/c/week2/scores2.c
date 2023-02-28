#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Score: \n");
        scanf("%i", &scores[i]);
    }

    printf("Average of scores is: %f\n", (scores[0] + scores[1] + scores[2] + scores[3] + scores[4]) / 5.0);
}