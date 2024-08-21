#include <stdio.h>

// This is an example of loops, I am interested in how this works.

#define ARR_LENGTH 10

void shellsort(int v[], int n);

int main()
{
    int arr[ARR_LENGTH];
    arr[0] = 8;
    arr[1] = 100;
    arr[2] = 20;
    arr[3] = 1;
    arr[4] = 5;
    arr[5] = 60;
    arr[6] = 30;
    arr[7] = 19;
    arr[8] = 14;
    arr[9] = 7;

    shellsort(arr, ARR_LENGTH);

    for (int i = 0; i < ARR_LENGTH; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}