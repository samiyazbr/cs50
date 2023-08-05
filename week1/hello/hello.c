#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? "); //get inout from user
    printf("hello, %s\n", name); //print name, (name that user input)
}