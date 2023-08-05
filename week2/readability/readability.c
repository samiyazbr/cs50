
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters = 0;
    string text = get_string("Text: ");
    letters = count_letters(text);
    // printf("%d letters\n", letters);

    int words = count_words(text);
    // printf("%d words\n", words);

    int sentences = count_sentences(text);
    // printf("%d sentences\n", sentences);

    double grade = 0.0588 * (letters * 100.0 / words) - 0.296 * (sentences * 100.0 / words) - 15.8;
    int roundedGrade = (int)round(grade);

    printf("final : %d\n", roundedGrade);
    if (roundedGrade >= 1 && roundedGrade <= 10)
    {
        printf("Grade %d\n", roundedGrade);
    }
    else if (roundedGrade > 10)
    {
        printf("Grade 16+\n");
    }
    else if (roundedGrade < 1)
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text) // counts the total number of letters in the text
{
    int letter_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int count_words(string text) //count number of words in the text
{
    int word_count = 1; // Start at 1 to account for the first word.
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text) //counts number of sentensec in the text
{
    int sentence_count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
