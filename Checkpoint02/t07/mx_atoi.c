#include <stdio.h>

#define MAX 2147483647
#define MIN -2147483647

int mx_atoi(const char *str);

int mx_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while(*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v')
    {
        str++;
    }

    if(*str == '+')
    {
        str++;
    } else if(*str == '-')
    {
        sign = -1;
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        int digit = *str - '0';

        if(MAX - digit < result)
        {
            if(sign == 1)
            {
                return MAX;
            } else
            {
                return MIN;
            }
        }

        result = result * 10 + digit;
        str++;
    }

    return result * sign;
}

