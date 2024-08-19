#include <stdio.h>

// Write a program to remove all comments from a C program. Don't forget to handle
// quoted strings and character constants properly. C comments do not nest.

#define TRUE 1
#define FALSE 0

void writeto(char c);
void ignoretonewline(void);
void ignoretoendofcomment(void);
int handlechar(char c);

int main()
{
    int c;
    int hadslash = FALSE;

    while ((c = getchar()) != EOF)
    {
        if (hadslash == TRUE)
        {
            if (c == '/')
            {
                ignoretonewline();
                hadslash = FALSE;
            }
            else if (c == '*')
            {
                ignoretoendofcomment();
                hadslash = FALSE;
            }
            else
            {
                putchar('/');
                hadslash = FALSE;
                hadslash = handlechar(c);
            }
        }
        else
        {
            hadslash = handlechar(c);
        }
    }
}

int handlechar(char c)
{
    int hadslash = FALSE;
    if (c == '\'')
    {
        putchar(c);
        writeto('\'');
    }
    else if (c == '"')
    {
        putchar(c);
        writeto('"');
    }
    else if (c == '/')
    {
        hadslash = TRUE;
    }
    else
    {
        putchar(c);
    }
    return hadslash;
}

void writeto(char endchar)
{
    int c;
    while ((c = getchar()) != endchar)
    {
        putchar(c);
    }
    putchar(c);
}

void ignoretonewline(void)
{
    int c;
    while ((c = getchar()) != '\n')
    {
    }
    putchar('\n');
}

void ignoretoendofcomment(void)
{
    int c;
    int lastc;
    while ((c = getchar()) != '/' || lastc != '*')
    {
        lastc = c;
    }
}