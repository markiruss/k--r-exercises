#include <stdio.h>

// Rewrite the function lower, which converts upper case letters to lowercase, with
// a conditional expression instread of if-else.

int lower(int c);

int main()
{
    int res = lower('M');
    printf("value: %c");

    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z')
               ? c + 'a' - 'A'
               : c;
}