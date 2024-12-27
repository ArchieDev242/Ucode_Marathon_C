#include "../inc/minilibmx.h"

int mx_atoi(const char *str) 
{
    int factor = 1;
    int result = 0;
    int i = 0;

    while(mx_isspace(str[i])) 
    {
        i++;
    }
   
    if(str[i] == '+' || str[i] == '-') 
    {
        factor = (str[i++] == '-' ? -1 : 1);
    }

    while(mx_isdigit(str[i])) 
    {
        result *= 10;
        result += str[i++] - 48;
    }

    return result * factor;
}

