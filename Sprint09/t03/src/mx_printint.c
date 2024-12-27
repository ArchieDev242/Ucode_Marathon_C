#include "header.h"

void mx_printint(int n)
{
    if (n < 0)
    {
        mx_printchar('-');
        n *= -1;
    }

    if (n >= 10)
    {
        mx_printint(n / 10);
    }
    mx_printchar(n % 10 + '0');
}

