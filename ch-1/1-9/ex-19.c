#include <stdio.h>

// Write a program to print all input lines that are longer than 80 caracters

#define MAXLINE 1000

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("Reverse: %s\n", line);
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

int reverse(char s[])
{
    int end = 0;
    while (s[end] != '\n')
        end++;

    end--;
    int start = 0;

    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
    return 0;
}
