#include <stdio.h>

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