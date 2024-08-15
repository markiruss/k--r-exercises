#include <stdio.h>

// Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve
// the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice
// to reach a tabstop, which should be given preference?

#define TABSIZE 8

int main()
{
    int c;
    int numBlanks = 0;
    int numTabs = 0;

    for (int pos = 1; (c = getchar()) != EOF; pos++)
    {
        if (c == ' ')
        {
            if (pos % TABSIZE == 0)
            {
                numBlanks = 0;
                numTabs++;
            }
            else
            {
                numBlanks++;
            }
        }
        else if (c == '\t')
        {
            numBlanks = 0;
            putchar(c);
            pos = pos + (pos % TABSIZE);
        }
        else
        {
            while (numTabs > 0)
            {
                putchar('\t');
                numTabs--;
            }
            while (numBlanks > 0)
            {
                putchar(' ');
                numBlanks--;
            }
            putchar(c);
            if (c == '\n')
            {
                pos = 0;
            }
        }
    }
}