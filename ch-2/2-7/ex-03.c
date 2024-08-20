#include <stdio.h>

// Write the function htoi(x), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The
// allowable digits are 0 through 9 a through f and A through F.

#define MAXLINE 1000

int htoi(char s[]);
int ishexchar(char c);
int gethexchar(char c);
int getline(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    while (getline(line, MAXLINE) > 0)
    {
        printf("value: %d\n", htoi(line));
    }
    return 0;
}

int htoi(char s[])
{
    int i;
    int n = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;

    while (ishexchar(s[i]))
    {
        n = 16 * n + gethexchar(s[i]);
        i++;
    }
    return n;
}

int ishexchar(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int gethexchar(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
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