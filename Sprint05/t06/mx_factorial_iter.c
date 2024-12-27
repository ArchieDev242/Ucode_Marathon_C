#include <stdio.h>

int mx_factorial_iter(int n);

int mx_factorial_iter(int n)
{
    int res = 1;
    int max = 2147483647;

    if(n < 0)
    {
        return 0;
    }

    if(n > max)
    {
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

