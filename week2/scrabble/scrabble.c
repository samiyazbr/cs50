#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!...");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins...");
    }
    else if (score1 == score2)
    {
        printf("Tie\n");
    }
}

int compute_score(string word) // this function calculate the score of the word
{
    // TODO: Compute and return score for string
    int i = 0;
    int score = 0;
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                  'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
                 };
    char ARR[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                  'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                 };
    while (islower(word[i]) || isupper(word[i])) //make sure there is any non-letter char and also handles upper and lowercase letter
    {
        int letter_pos = 0;
        while ((word[i] != arr[letter_pos]) && (word[i] != ARR[letter_pos])) // this loop is to finf which is the letter
        {
            letter_pos++;
        }
        score += POINTS[letter_pos];
        i++;
    }
    return (score);
}
