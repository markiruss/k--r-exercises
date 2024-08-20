#include <stdio.h>

// Write the function any(s1, s2), which returns the first location in the string s1
// where any character from the string s2 occurs, or -1 if s1 contains no charcters
// from s2. (The standard library fuction strpbrk does the same job but returns a
// pointer to the location)

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int any(char s1[], char s2[]);
int exists(char s[], char c);

int main()
{
    char s1[MAXLINE] = "mark russell7";
    char s2[MAXLINE] = "789532786153458646545374864653453";

    int location = any(s1, s2);

    printf("location: %d", location);
}

int any(char s1[], char s2[])
{
    int i;
    int returnval = -1;
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (exists(s2, s1[i]) == TRUE)
        {
            return i;
        }
    }
    return -1;
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