#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float count_letters(char *text);
float count_words(char *text);
float count_sentences(char *text);
int grade_text(char *text);

/*
- C implementation of the Coleman-Liau index for
... determining the U.S. grade level of given text.
*/
int main(int argc, char *argv[])
{
    int text_buffer_size = 1024 * sizeof(char);
    char *text = malloc(text_buffer_size);
    printf("Text: ");
    fgets(text, text_buffer_size, stdin);

    int grade = grade_text(text);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    free(text);

    return 0;
}

int grade_text(char *text)
{
    float letter_count = count_letters(text);
    float word_count = count_words(text);
    float sentence_count = count_sentences(text);

    float index = 0.0588 * letter_count / word_count * 100 - 0.296 * sentence_count / word_count * 100 - 15.8;
    index = round(index);
    int integer_index = index;

    return integer_index;
}

float count_letters(char *text)
{
    float counter = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }

    return counter;
}

float count_words(char *text)
{
    float word_counter = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            word_counter++;
        }
    }

    return word_counter;
}

float count_sentences(char *text)
{
    float sentence_counter = 0;

    // iterate over text
    for (int i = 0; i < strlen(text); i++)
    {
        // ! . ?
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence_counter++;
        }
    }

    return sentence_counter;
}