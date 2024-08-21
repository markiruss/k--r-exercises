#include <stdio.h>

// Write a function rightrot(x,n) that returns the value of integer x rotated to the
// right by n bit positions

unsigned rightrot(unsigned x, int n);

int main()
{
    unsigned res = rightrot(10, 4);
    printf("value: %u", res);

    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Is the last bit a 1?
        int lastbit = x & 1;
        x = x >> 1;
        if (lastbit)
        {
            // Put the bit at the beginning
            x = x | ~(~0u >> 1);
        }
    }
    return x;
}