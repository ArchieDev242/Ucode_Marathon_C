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
        } else
        {
            sign = 1;
        }
        i++;
    }

    while(mx_isdigit(str[i])) 
    {
        int digit = str[i] - '0';
        int max = 2147483647;
        int min = -2147483648;

        if(result > (max - digit) / 10)
        {
            if(sign == 1)
            {
                return max;
            } else
            {
                return min;
            }
        }
        
        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

