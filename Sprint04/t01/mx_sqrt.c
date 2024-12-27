#include <stdio.h>

int mx_sqrt(int x);

int mx_sqrt(int x) 
{
    int sqrt_num = 1;

    while(sqrt_num <= x / sqrt_num)
    {
        if(sqrt_num * sqrt_num == x) 
        {
            return sqrt_num;
        }
        sqrt_num++;
    }
    return 0;
}

