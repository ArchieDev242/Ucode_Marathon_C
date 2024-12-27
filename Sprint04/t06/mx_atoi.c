#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);

int mx_atoi(const char *str)
{
    int sign = 1;
    int result = 0;

    while(mx_isspace(*str))
    {
        str++;
    }

    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
        {
            sign = -1;
        } else
        {
            sign = 1;
        }
        str++;
    }

    while(*str >= '0' && *str <= '9') 
    {
        int max = 2147483647;
        int min = -2147483648;

        if(result > (max - (*str - '0')) / 10)
        {
            if(sign == 1)
            {
                return max;
            } else
            {
                return min;
            }
        }
        
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

