#include "../inc/header.h"

void mx_printint(int n) 
{
    long temp_num = n;

    if(temp_num < 0) 
    {
        mx_printchar('-');
        temp_num *= -1;
    }

    int next_num = temp_num / 10;

    if(next_num) 
    {
        mx_printint(next_num);
    }

    mx_printchar((temp_num % 10) + 48);
}

