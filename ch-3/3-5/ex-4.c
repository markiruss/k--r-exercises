#include <stdio.h>
#include <string.h>
#include <limits.h>

// In a two's compliment number representation, our version of itoa does not handle the largest
// negative number, that is, the value of n Equal to -(2^(wordsize-1)). Explain why not. Modify it
// to print that value correctly, regardless fo the machine on which it runs.

// In a two's compliment number the largest negative number is 1 further from zero than the largest
// positive number, so you cannot get n = -n for this value.

void itoaorig(int n, char a[]);
void reverse(char s[]);

int main()
{
    char arr[100];

    itoaorig(INT_MIN, arr);

    printf("value: %s", arr);

    return 0;
}

void itoaorig(int n, char s[])
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