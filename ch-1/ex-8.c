#include <stdio.h>

// Write a program to count blanks, tabs and newlines
int main()
{
    int c, blanks, tabs, newlines;
    blanks = tabs = newlines = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            newlines++;

        if (c == '\t')
            tabs++;

        if (c == ' ')
            blanks++;
    }

    printf("%4d%4d%4d\n", blanks, tabs, newlines);
    printf("goodbye\n");
}