#include <stdio.h>

// Write a funciton itob(n,s,b) that converts the integer 1 into a base b character
// representation in the string s. In particular, itob(n,s,16 formats n as a hexadecimal
// integer in s.

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char arr[100];

    itob(15, arr, 16);

    printf("value: %s", arr);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign, multiplier;
    multiplier = 1;
    if ((sign = n) < 0)
        multiplier = -1;
    i = 0;
    do
    {
        int remainder = multiplier * (n % b);
        if (remainder > 9)
        {
            s[i++] = multiplier * (n % b) + 'A' - 10;
        }
        else
        {
            s[i++] = multiplier * (n % b) + '0';
        }
    } while ((n /= b) != 0);

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