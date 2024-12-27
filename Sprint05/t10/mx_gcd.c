#include <stdio.h>

int mx_gcd(int a, int b);

int mx_gcd(int a, int b)
{
    if(a < 0)
    {
        a *= -1;
    }

    if(b < 0)
    {
        b *= -1;
    }

    while(b != 0)
    {
        int sum = b;
        b = a % b;
        a = sum;
    }

    return a;
}

