#include <stdio.h>

// for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c

// Write a loop equivelent to the for loop above without using && or ||

#define LIMIT 10

// This was my original solution, the issue is that using the + does not short circuit the
// evaluation. If the limit is reached, getchar will still be called, and thus a char will
// be missed if getchar is to be called outside of the loop
// int main()
// {
//     int i, c;
//     int lim = LIMIT;
//     char s[LIMIT];
//     for (i = 0; (i < lim - 1) + ((c = getchar()) != '\n') + (c != EOF) == 3; ++i)
//         s[i] = c;
// }

// This is the K&R solution with short circuit logic
int main()
{
    int i, c;
    int lim = LIMIT;
    char s[LIMIT];
    enum boolean
    {
        FALSE,
        TRUE
    };
    int loopok = TRUE;

    while (loopok == TRUE)
    {
        if (i >= lim - 1)
        {
            loopok = FALSE;
        }
        else if ((c = getchar()) == '\n')
        {
            loopok = FALSE;
        }
        else if (c == EOF)
        {
            loopok = FALSE;
        }
        else
        {
            s[i] = c;
            i++;
        }
    }
}
