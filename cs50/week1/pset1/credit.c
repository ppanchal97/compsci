#include <stdio.h>
#include <string.h>

void validate_card(char *card_number);
void print_card_type(char *card_number);

/*
- C implementation of Luhn's algorithm for checking
... validity of a credit card number.
*/
int main(void)
{
    long ccn;
    printf("Number: ");
    scanf("%ld", &ccn);
    char card_number[256];
    sprintf(card_number, "%ld", ccn);
    validate_card(card_number);
}

void validate_card(char *card_number)
{
    int step_1_digit_product = 0;
    int step_2_digit_product = 0;

    // find every other digit starting from the second-last
    for (int i = strlen(card_number) - 2; i >= 0; i -= 2)
    {
        // convert to int and multiply by 2
        int x = card_number[i] - '0';
        x *= 2;

        if (x >= 10)
        {
            step_1_digit_product += (x - 10 + 1);
        }
        else
        {
            step_1_digit_product += x;
        }
    }

    // find every other digit starting from the last
    for (int i = strlen(card_number) - 1; i >= 0; i -= 2)
    {
        int x = card_number[i] - '0';
        step_2_digit_product += x;
    }

    int total_sum = step_1_digit_product + step_2_digit_product;

    // check validity of first 2 digits and card length
    if (total_sum % 10 == 0 && strlen(card_number) >= 13 && strlen(card_number) <= 16)
    {
        // determine card type
        print_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

void print_card_type(char *card_number)
{
    if (card_number[0] == '4')
    {
        printf("VISA\n");
    }
    else if (card_number[0] == '3' && (card_number[1] == '4' || card_number[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if (card_number[0] == '5' && (card_number[1] == '1' || card_number[1] == '2' || card_number[1] == '3' || card_number[1] == '4' || card_number[1] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        // Unrecognized brand, but valid card
        printf("INVALID\n");
    }
}