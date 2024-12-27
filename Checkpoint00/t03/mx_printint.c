#include <stdio.h>
#include <unistd.h>

void mx_printint(int n);

void mx_printint(int n)
{
    if(n < 0)
    {
        write(1, "-", 1);
        n *= -1;
    }

    if(n >= 10)
    {
        mx_printint(n / 10);
    }

    char digits = n % 10 + '0';

    write(1, &digits, 1);
}

