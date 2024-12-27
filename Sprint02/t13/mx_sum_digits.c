#include <stdio.h>

int mx_sum_digits(int num);

int mx_sum_digits(int num)
{
    if(num < 0)
    {
        num *= -1;
    }

    int digit = 0;

    while(num > 0)
    {
        digit += num % 10;

        num /= 10;
    }

    return digit;
}

