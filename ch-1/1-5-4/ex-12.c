#include <stdio.h>

#define IN 1
#define OUT 0

// Write a program that prints its input one word per line
int main()
{
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (state == IN)
            {
                putchar('\n');
                state = OUT;
            }            
        }
        else
        {
            putchar(c);
            state = IN;
        }
    }

    printf("goodbye\n");
}