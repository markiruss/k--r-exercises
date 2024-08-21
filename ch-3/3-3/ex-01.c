#include <stdio.h>

// Our binary search makes two tests inside the loop, when only one would suffice (at
// the price of more tests outside). Write a version with only one test inside the
// loop and measure the difference in run-time.

#define ARR_LENGTH 10

int binsearchorig(int x, int v[], int n);
int binsearchnew(int x, int v[], int n);

int main()
{
    int arr[ARR_LENGTH];
    for (int i = 0; i < ARR_LENGTH; i++)
    {
        arr[i] = i;
    }

    int index = binsearchnew(4, arr, ARR_LENGTH);
    printf("position: %d", index);

    return 0;
}

int binsearchorig(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// I haven't benchmarked it, but apparently the gain in speed is minimal, and readability is worse
int binsearchnew(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid])
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = (low + high) / 2;
    }
    return x == v[mid] ? mid : -1;
}