#include <stdio.h>
#include <unistd.h>

int mx_atoi(const char *str);

int mx_atoi(const char *str)
{
    int result = 0;
    int sign = 1;

    while(*str == ' ' || (*str >= '\t' && *str <= '\r')) 
    {
        str++;
    }

    if(*str == '-') 
    {
        sign = -1;
        str++;
    } else if(*str == '+') 
    {
        sign = 1;
        str++;
    } else 
    {
        sign = 1;
    }

    while(*str >= '0' && *str <= '9') 
    {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

