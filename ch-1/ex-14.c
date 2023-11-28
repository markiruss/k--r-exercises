#include <stdio.h>

// Rewrite the temperature conversion program of
// Section 1.2 to use a function for conversion
float fahrToCelcius(float fahr);

int main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper)
    {
        celcius = fahrToCelcius(fahr);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }

    return 0;
}

float fahrToCelcius(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}