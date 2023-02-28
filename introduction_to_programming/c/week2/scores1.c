#include <stdio.h>

int main(void)
{
    int scores[3] = {5,3,1};
    printf("Average of scores is: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}