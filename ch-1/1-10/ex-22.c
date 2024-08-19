#include <stdio.h>

// Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character
// that occurs before the n-th column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column

#define MAXLINE 10
#define TRUE 1
#define FALSE 0

int writeword(int word[], int wordlength, int pos, int maxline);

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
                if (pos > MAXLINE)
                {
                    putchar('\n');
                    pos = 0;
                }
                putchar(c);
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
                if (pos > MAXLINE)
                {
                    putchar('\n');
                    pos = 0;
                }
                putchar(c);
                if (c == '\n')
                {
                    pos = 0;
                }
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