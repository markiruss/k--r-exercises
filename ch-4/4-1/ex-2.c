#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main()
{
    double atof(char[]);

    double num = atof("+456e1");
    printf("num is %f", num);

    return 0;
}

double atof(char s[])
{
    double val, power, exponent;
    int i, sign, exponentsign;

    // skip whitespace
    for (i = 0; isspace(s[i]); i++)
    {
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    val = sign * val / power;
    if (s[i] == 'e' || s[i] == 'e')
    {
        i++;
        exponentsign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }
        for (exponent = 0.0; isdigit(s[i]); i++)
        {
            exponent = 10.0 * exponent + (s[i] - '0');
        }
        if (exponentsign < 0)
        {
            for (; exponent > 0; exponent--)
            {
                val /= 10;
            }
        }
        else
        {
            for (; exponent > 0; exponent--)
            {
                val *= 10;
            }
        }
    }
    return val;
}
