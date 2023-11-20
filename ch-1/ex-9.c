#include <stdio.h>

// Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.
int main()
{
    int c;
    int inspace = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (inspace != 1)
            {
                inspace = 1;
                putchar(c);
            }
        }
        else
        {
            inspace = 0;
            putchar(c);
        }
    }

    printf("goodbye\n");
}