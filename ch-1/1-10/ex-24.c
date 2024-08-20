#include <stdio.h>

// Write a program to check a C program for ruudimentary syntax errors like unbalanced
// parenthesis, brackets, and braces. Don't forget about quotes, both single and double,
// escape sequenses, and comments. (This program is hard if you do it in full generality.)

#define TRUE 1
#define FALSE 0

void writeto(char c);
int ignoretonewline(void);
int ignoretoendofcomment(void);

int main()
{
    int c;

    int parenthesiscount = 0;
    int bracketcount = 0;
    int bracecount = 0;
    int quotecount = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '/')
        {
            c = getchar();
            if (c == '/')
            {
                quotecount = ignoretonewline();
            }
            else if (c == '*')
            {
                quotecount = ignoretoendofcomment();
            }
            else
            {
                putchar('/');
                putchar(c);
            }
        }
        else if (c == '\'')
        {
            putchar(c);
            writeto('\'');
        }
        else if (c == '"')
        {
            putchar(c);
            writeto('"');
        }
        else
        {
            if (c == '(')
            {
                parenthesiscount++;
            }
            else if (c == ')')
            {
                parenthesiscount--;
            }
            else if (c == '[')
            {
                bracketcount++;
            }
            else if (c == ']')
            {
                bracketcount--;
            }
            else if (c == '{')
            {
                bracecount++;
            }
            else if (c == '}')
            {
                bracecount--;
            }
            putchar(c);
        }
    }

    if (parenthesiscount != 0)
    {
        printf("Unbalanced parenthesis\n");
    }

    if (bracketcount != 0)
    {
        printf("Unbalanced brackets\n");
    }

    if (bracecount != 0)
    {
        printf("Unbalanced braces\n");
    }

    if (quotecount != 0)
    {
        printf("Unbalanced quote\n");
    }
}

void writeto(char endchar)
{
    int c;
    while ((c = getchar()) != endchar)
    {
        putchar(c);
        if (c == '\\')
        {
            putchar(getchar());
        }
    }
    putchar(c);
}

int ignoretonewline(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    if (c == EOF)
    {
        return 1;
    }
    else
    {
        putchar('\n');
        return 0;
    }
}

int ignoretoendofcomment(void)
{
    int c;
    int lastc;
    while (((c = getchar()) != '/' || lastc != '*') && c != EOF)
    {
        lastc = c;
    }
    if (c == EOF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}