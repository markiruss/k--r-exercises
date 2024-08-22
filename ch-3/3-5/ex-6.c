#include <stdio.h>
#include <string.h>
#include <limits.h>

// Write a version of itoa that accepts three arguments instead of two. The third argument
// is a minimum field width; the converted number must be padded with blanks on the left
// if necessary to make it wide enough

void itoa(int n, char a[], int min_w);
void reverse(char s[]);

int main()
{
    char arr[100];

    itoa(500, arr, 10);

    printf("%s", arr);

    return 0;
}

void itoa(int n, char s[], int min_w)
{
    int i, sign, multiplier;
    multiplier = 1;
    if ((sign = n) < 0)
        multiplier = -1;
    i = 0;
    do
    {
        s[i++] = multiplier * (n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < min_w)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}