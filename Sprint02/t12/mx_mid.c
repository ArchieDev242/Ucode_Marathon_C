#include <stdio.h>

int mx_mid(int a, int b, int c);

int mx_mid(int a, int b, int c)
{
    if((a >= b && a <= c) || (a >= c && a <= b))
    {
        return a;
    } else if((b >= a && b <= c) || (b >= c && b <= a))
    {
        return b;
    } else
    {
        return c;
    }
}

