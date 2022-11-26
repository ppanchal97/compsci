#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = malloc(20);
    const int strings_memory = 128;

    printf("Name to lookup: ");
    scanf("%s", s);

    char *names[strings_memory] = {"David", "Carter", "Coulton", "Brian"};
    char *phone_numbers[strings_memory] = {"+1324124234", "+14234223453", "+1802312341", "+19821312323"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(s, names[i]) == 0)
        {
            printf("Phone number: %s\n", phone_numbers[i]);
            return 0;
        }
    }
    printf("Contact not found\n");
    return 1;
}