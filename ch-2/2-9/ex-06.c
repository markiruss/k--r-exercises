#include <stdio.h>

// Write a function setbits(x,p,b,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged.

unsigned setbits(unsigned x, int p, int n, int y);

int main()
{
    unsigned res = setbits(255, 5, 2, 252);
    printf("value: %u", res);

    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    y = (y & ~(~0 << n)) << (p - n);
    x = x & ~(~(~0 << n) << (p - n));
    return y | x;
}
