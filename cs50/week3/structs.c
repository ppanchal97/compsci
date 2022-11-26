#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
- C program to demonstrate structs, including limitations.
*/
typedef struct
{
    char *name;
    int age;
    char *phone_number;
} person;

int main(void)
{
    char *lookup_name = malloc(20);
    const int strings_memory = 128;

    printf("Name to lookup: ");
    scanf("%s", lookup_name);

    person phonebook[3];

    // initialize values
    phonebook[0].name = "David";
    phonebook[0].age = 33;
    phonebook[0].phone_number = "+132412423412";

    phonebook[1].name = "Carter";
    phonebook[1].age = 23;
    phonebook[1].phone_number = "+123423412442";

    phonebook[2].name = "Brian";
    phonebook[2].age = 22;
    phonebook[2].phone_number = "+198712361731";

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(lookup_name, phonebook[i].name) == 0)
        {
            printf("Phone number: %s\n", phonebook[i].phone_number);
            return 0;
        }
    }
    printf("Contact '%s' not found\n", lookup_name);
    return 1;
}