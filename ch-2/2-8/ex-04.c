#include <stdio.h>

// Write an alternative version of squeeze(s1, s2) thast deletes each character
// in s1 that matches any character in the string s2.

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]);
int exists(char s[], char c);

int main()
{
    char s1[MAXLINE] = "mark russell";
    char s2[MAXLINE] = "aeiou";

    squeeze(s1, s2);

    printf("s1: %s", s1);
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (exists(s2, s1[i]) == FALSE)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int exists(char s[], char c)
{
    int curr;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return TRUE;
        }
    }
    return FALSE;
}