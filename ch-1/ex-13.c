#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_SIZE 10

// Write a program to print a histogram of the lengths of words in its input.
// It is easy to draw the histogram with the bars horizontal; a vertical orientation
// is more challenging.
int main()
{

    int charcount[MAX_WORD_SIZE];

    for (int i = 0; i < MAX_WORD_SIZE; i++)
        charcount[i] = 0;

    int currentword = 0;
    int state = OUT;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            if (state == IN)
            {
                if (currentword > MAX_WORD_SIZE)
                {
                    currentword = MAX_WORD_SIZE;
                }
                charcount[currentword - 1]++;
            }
            state = OUT;
            currentword = 0;
        }
        else
        {
            state = IN;
            currentword++;
        }
    }

    printf("Horizontal hostogram\n");
    for (int i = 0; i < MAX_WORD_SIZE; i++)
    {
        printf("%2d:", i + 1);
        for (int j = 0; j < charcount[i]; j++)
            putchar('=');
        putchar('\n');
    }

    putchar('\n');
    printf("Vertical histogram\n");

    int highestCount = 0;
    for (int i = 0; i < MAX_WORD_SIZE; i++)
    {
        if (charcount[i] > highestCount)
            highestCount = charcount[i];
    }

    for (int i = highestCount; i > 0; i--)
    {
        for (int j = 0; j < MAX_WORD_SIZE; j++)
        {
            if (charcount[j] >= i)
                printf("| ");
            else
                printf("  ");
        }
        putchar('\n');
    }
    printf("1 2 3 4 5 6 7 8 9 10\n");
    printf("goodbye\n");
}