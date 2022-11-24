#include <stdio.h>

/*
- passing in variables through the CLI
- argc: argument count
- argv: argument values, start from argv[1] for user input
*/ 
int main(int argc, char *argv[])
{
    if (argc == 2) {
        printf("Hello, %s\n", argv[1]);
    }
    else
    {
        printf("failed to provide required second argument 'name'\n");
    }
}