#include <stdio.h>

int mx_max(int a, int b, int c);

int mx_max(int a, int b, int c)
{
    if(a >= b && a >= c)
    {
        return a;
    } else if(b >= a && b >= c)
    {
        return b;
    } else
    {
        return c;
    }
}

