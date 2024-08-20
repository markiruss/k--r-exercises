#include <stdio.h>
#include <limits.h>
#include <float.h>

// Write a program to determin the ranges of char, short, int, and long variables,
// both signed and unsigned, by printing appropriate values from standard variables
// headers and by direct computation. Harder if you compute them: determine the
// rangest of the various floating-point types
char minchar(void);
char maxchar(void);
short minshort(void);
short maxshort(void);
int minint(void);
int maxint(void);
long minlong(void);
long maxlong(void);
unsigned char maxuchar(void);
unsigned short maxushort(void);
unsigned int maxuint(void);
unsigned long maxulong(void);

int main()
{
    printf("FROM HEADERS\n");
    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("long min: %d\n", LONG_MIN);
    printf("long max: %d\n", LONG_MAX);

    printf("uchar min: %d\n", 0);
    printf("uchar max: %u\n", UCHAR_MAX);
    printf("ushort min: %d\n", 0);
    printf("ushort max: %u\n", USHRT_MAX);
    printf("uint min: %d\n", 0);
    printf("uint max: %u\n", UINT_MAX);
    printf("ulong min: %d\n", 0);
    printf("ulong max: %u\n", ULONG_MAX);

    printf("float min: %f\n", FLT_MIN);
    printf("float max: %f\n", FLT_MAX);
    printf("double min: %lf\n", DBL_MIN);
    printf("double max: %lf\n", DBL_MAX);

    // K&R answer book suggests using bitwise expressions for calcualting
    // but as we haven;t covered them yout I am using brute force
    printf("\nCALCULATED\n");
    printf("char min: %d\n", minchar());
    printf("char max: %d\n", maxchar());
    printf("short min: %d\n", minshort());
    printf("short max: %d\n", maxshort());
    printf("int min: %d\n", minint());
    printf("int max: %d\n", maxint());
    printf("long min: %ld\n", minlong());
    printf("long max: %ld\n", maxlong());

    printf("uchar min: %d\n", 0);
    printf("uchar max: %u\n", maxuchar());
    printf("ushort min: %d\n", 0);
    printf("ushort max: %u\n", maxushort());
    printf("uint min: %d\n", 0);
    printf("uint max: %u\n", maxuint());
    printf("ulong min: %d\n", 0);
    printf("ulong max: %lu\n", maxulong());
}

char minchar(void)
{
    char curr = -1;
    char prev = 0;
    while (curr < prev)
    {
        prev = curr;
        curr--;
    }
    return prev;
}

char maxchar(void)
{
    char curr = 1;
    char prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

short minshort(void)
{
    short curr = -1;
    short prev = 0;
    while (curr < prev)
    {
        prev = curr;
        curr--;
    }
    return prev;
}

short maxshort(void)
{
    short curr = 1;
    short prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

int minint(void)
{
    int curr = -1;
    int prev = 0;
    while (curr < prev)
    {
        prev = curr;
        curr--;
    }
    return prev;
}

int maxint(void)
{
    int curr = 1;
    int prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

long minlong(void)
{
    long curr = -1;
    long prev = 0;
    while (curr < prev)
    {
        prev = curr;
        curr--;
    }
    return prev;
}

long maxlong(void)
{
    long curr = 1;
    long prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

unsigned char maxuchar(void)
{
    unsigned char curr = 1;
    unsigned char prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

unsigned short maxushort(void)
{
    unsigned short curr = 1;
    unsigned short prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

unsigned int maxuint(void)
{
    unsigned int curr = 1;
    unsigned int prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}

unsigned long maxulong(void)
{
    unsigned long curr = 1;
    unsigned long prev = 0;
    while (curr > prev)
    {
        prev = curr;
        curr++;
    }
    return prev;
}