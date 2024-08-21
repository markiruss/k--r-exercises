#include <stdio.h>

// Write a function escape(s, t) that converts characters likenewline and tab into
// visible escape sequences like \n and \t as it copies the string t to s. Use a switch.
// Write a function for the other direction as well converting excape sequences into
// the real characters.

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char destination[1000];

    unescape(destination, "\\nusss\\t\\tskldfj");

    printf("value: %s", destination);

    return 0;
}

void escape(char s[], char t[])
{
    int sindex = 0;
    int tindex = 0;

    for (; t[tindex] != '\0'; tindex++)
    {
        switch (t[tindex])
        {
        case '\n':
            s[sindex++] = '\\';
            s[sindex++] = 'n';
            break;

        case '\t':
            s[sindex++] = '\\';
            s[sindex++] = 't';
            break;

        default:
            s[sindex++] = t[tindex];
            break;
        }
    }
    s[sindex] = '\0';
}

void unescape(char s[], char t[])
{
    int sindex = 0;
    int tindex = 0;

    while (t[tindex] != '\0')
    {
        switch (t[tindex++])
        {
        case '\\':
            switch (t[tindex++])
            {
            case 't':
                s[sindex++] = '\t';
                break;

            case 'n':
                s[sindex++] = '\n';
                break;

            default:
                s[sindex++] = '\\';
                s[sindex++] = t[tindex - 1];
                break;
            }
            break;

        default:
            s[sindex++] = t[tindex - 1];
            break;
        }
    }
    s[sindex] = '\0';
}
