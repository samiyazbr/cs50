#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string input = get_string("Message: "); // getting the user input
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        int byte[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int ascii = input[i]; // convets char into ascii value
        for (int j = 0; ascii > 0;
             j++) // this loop converts ascii into binary but reversed (if crrct byte = 00000100 this loop returns 00100000)
        {
            byte[j] = ascii % 2;
            ascii = ascii / 2;
        }
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--) //print the bulb from left to right(i,e the correct order)
        {
            print_bulb(byte[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit) // this function prints the bulb
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

