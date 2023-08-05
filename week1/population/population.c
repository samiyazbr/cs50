#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start;

    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size

    int end;

    do
    {
        end = get_int("End Size: ");
    }
    while (start > end);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    int gain = 0;
    int loss = 0;

    while (start < end)
    {
        gain = start / 3;
        loss = start / 4;
        start = start + gain - loss;
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i", years);
}
