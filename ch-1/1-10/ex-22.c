#include <stdio.h>

// Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character
// that occurs before the n-th column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column

#define MAXLINE 10
#define TABWIDTH 4
#define TRUE 1
#define FALSE 0

int writeword(int word[], int wordlength, int pos, int maxline);
int writewhitespace(int c, int pos, int maxline, int tabwidth);

int main()
{
    int c;
    int inword = FALSE;
    int wordbufferpos = 0;
    int wordbuffer[MAXLINE];
    for (int pos = 1; (c = getchar()) != EOF; pos++)
    {
        if (inword == FALSE)
        {
            if (c != '\t' && c != ' ' && c != '\n')
            {
                wordbuffer[wordbufferpos] = c;
                wordbufferpos++;
                inword = TRUE;
            }
            else
            {
                pos = writewhitespace(c, pos, MAXLINE, TABWIDTH);
            }
        }
        else
        {
            if (c != '\t' && c != ' ' && c != '\n')
            {
                if (wordbufferpos == MAXLINE)
                {
                    pos = writeword(wordbuffer, wordbufferpos, pos, MAXLINE);
                    wordbufferpos = 0;
                    putchar('\n');
                    wordbuffer[wordbufferpos] = '-';
                    wordbufferpos++;
                    pos = 0;
                }
                wordbuffer[wordbufferpos] = c;
                wordbufferpos++;
                inword = TRUE;
            }
            else
            {
                pos = writeword(wordbuffer, wordbufferpos, pos, MAXLINE);
                wordbufferpos = 0;
                pos = writewhitespace(c, pos, MAXLINE, TABWIDTH);
                inword = FALSE;
            }
        }
    }
}

int writeword(int word[], int wordlength, int pos, int maxline)
{
    if (pos > maxline + 1)
    {
        putchar('\n');
        pos = wordlength;
    }
    for (int i = 0; i < wordlength; i++)
    {
        putchar(word[i]);
    }
    return pos;
}

int writewhitespace(int c, int pos, int maxline, int tabwidth)
{
    if (pos > MAXLINE)
    {
        putchar('\n');
        pos = 0;
    }
    if (c == '\t')
    {
        int i = tabwidth;
        while (i > 0)
        {
            if (pos > MAXLINE)
            {
                putchar('\n');
                pos = 0;
            }
            putchar(' ');
            if (i > 1)
            {
                // Not on the last one otherwise there will be too many increments
                pos++;
            }
            i--;
        }
    }
    else
    {
        putchar(c);
    }
    if (c == '\n')
    {
        pos = 0;
    }
    return pos;
}