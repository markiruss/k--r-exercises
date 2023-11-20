#include <stdio.h>

// Write a probram to copy its input to its output, replacing each tab by \t,
// each backspace by \b, and each backslash by \\. This makes tabs and backspaces
// visible in an un ambigious way.
int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else
        {
            putchar(c);
        }
    }

    printf("goodbye\n");
}