#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

// Write the function strrindex(s, t), which returns the position of the rightmost occurence of t
// in s, or -1 if there is none.

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    char line[MAXLINE];
    int found = 0;
    int index;
    while (getline(line, MAXLINE) > 0)
    {
        if ((index = strrindex(line, pattern)) >= 0)
        {
            printf("%s", line);
            printf("index is %d\n", index);
            found++;
        }
    }
    return found;
}

int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }

    if (c == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
}

int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - 1; i >= 0; i--)
    {
        for (j = i, k = 0; t[k] != '\0' & s[j] == t[k]; j++, k++)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}