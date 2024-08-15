#include <stdio.h>

// Revise the main routine of the longest-line program so it will correctly print the length
// of arbitrarily long input lines, and as much as possible of the text

#define MAXLINE 10

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n' && line[len - 1] != EOF)
        {
            int c;
            // There is more to the input so loop. Should be done in the getline
            // func, but the working of the questions suggests to do it here
            while ((c = getchar()) != '\n')
                len++;

            if (c == '\n')
                len++;
        }
        printf("\nLine Length: %d\n%s\n\n", len, line);
    }
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}
