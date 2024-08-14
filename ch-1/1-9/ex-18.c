#include <stdio.h>

// Write a program to print all input lines that are longer than 80 caracters

#define MAXLINE 1000

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        int newlen = trimend(line);
        if (newlen > 1)
        {
            printf("\nLine Length: %d\n%s\n", newlen, line);
        }
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

int trimend(char s[])
{
    int i = 0;
    int lastnonwhitespace = -1;
    while (s[i] != '\0')
    {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
        {
            lastnonwhitespace = i;
        }
        i++;
    }
    s[++lastnonwhitespace] = '\n';
    s[++lastnonwhitespace] = '\0';
    return lastnonwhitespace;
}
