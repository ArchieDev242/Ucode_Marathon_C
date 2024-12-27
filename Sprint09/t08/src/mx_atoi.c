#include "minilibmx.h"

int mx_atoi(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while(mx_isspace(str[i]))
    {
        i++;
    }

    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign = -1;
        } else if(str[i] == '+')
        {
            sign = 1;
        }
        i++;
    }

    while(mx_isdigit(str[i])) 
    {
        int max = 2147483647;
        int min = -2147483648;

        if(result > max / 10 || (result == max / 10 && str[i] - '0' > 7))
        {
            if(sign == 1)
            {
                return max;
            } else
            {
                return min;
            }
        }
        
        result = result * 10 + (str[i++] - '0');
    }

    return result * sign;
}

