#include "../inc/minilibmx.h"

void mx_printint(int n) 
{
    long temp = n;

    if(temp < 0) 
    {
        mx_printchar('-');
        temp *= -1;
    }

    int n_next = temp / 10;

    if(n_next) 
    {
        mx_printint(n_next);
    }

    mx_printchar((temp % 10) + 48);
}

