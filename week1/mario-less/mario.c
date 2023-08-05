#include <cs50.h>
#include <stdio.h>


int get_height(void) // function to get height from the user
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8);
    return n;
}

void print_pyramid(int n) //function to print pyramid
{
    int i = 0;
    while (i < n)
    {
        for (int k = 2; k <= n - i; k++) // it will print the (n - i) no of spaces before the # n = height, i = current height
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) // it will print n no of # in nth row
        {
            printf("#");
        }
        printf("\n");
        i++;
    }
}
int main(void)
{
    int n = get_height();
    print_pyramid(n);
}
