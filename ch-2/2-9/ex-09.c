#include <stdio.h>

// In a two's compliment number system, x &= (x - 1) delets the rightmost 1-bit in x. Explain why.
// Use this observation to write a faster version of bitcount

// Minusing 1 from a number will effectively take the last 1 bit, turn it to a zero, and everything
// to the right of that bit will be a 1. It's easier to think of it the opposite, if you have the
// number 1011 and add one to it, the two 1's will flip to 0, and the first 0 from the right will
// flip to 1, giving you 1100. So when minusing 1 the 1100 will be 1011

// If you take the original 1100 and do a bitwise and with the new 1011, you have 1000, which has
// just deleted the last 1

// This only works with two's complement, because when you minus 1 from a negative number, the bits flip the
// same way as with a positive number

int bitcount(unsigned x);

int main()
{
    int count = bitcount(8181);
    printf("value: %d", count);

    return 0;
}

int bitcount(unsigned x)
{
    int b = 0;
    while (x > 0)
    {
        x &= (x - 1);
        b++;
    }
    return b;
}