#include <stdio.h>
#include <string.h>

// Write a function expand(s1,s2) that expands shorthand notation like a-z in
// the string s1 into the equivalent complete list abc...xyz in s2. Allow for
// letters of either case and digits, and be prepared to handle cases like a-b-c
// and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literaly.

void expand(char s1[], char s2[]);
int checkmatch(char c1, char c2);

int main()
{
    char arr[1000];
    expand("-this 1-8-d-u B-R is a testee-", arr);
    printf("%s", arr);

    return 0;
}

void expand(char s1[], char s2[])
{
    int l = strlen(s1);
    int i, j;
    for (i = 0, j = 0; i < l; i++)
    {
        if (s1[i] == '-' && i != 0 && i != l - 1)
        {
            if (checkmatch(s1[i - 1], s1[i + 1]))
            {
                char c;
                for (int k = 1; (c = s1[i - 1] + k) < s1[i + 1]; k++)
                {
                    s2[j++] = c;
                }
            }
            else
            {
                s2[j++] = s1[i];
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int checkmatch(char c1, char c2)
{
    return c1 < c2 && ((c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z') || (c1 >= 'A' && c1 <= 'Z' && c2 >= 'A' && c2 <= 'Z') || (c1 >= '0' && c1 <= '9' && c2 >= '0' && c2 <= '9'));
}