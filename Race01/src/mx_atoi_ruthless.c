#include "../inc/minilibmx.h"

int mx_atoi_ruthless(const char *str) 
{
    int factor = 1;
    int num = 0;
    int i = 0;

    if(str[i] == '+' || str[i] == '-') 
    {
        factor = (str[i++] == '-' ? -1 : 1);
    }

    while(str[i] != '\0') 
    {
        if(!mx_isdigit(str[i])) 
        {
            return 0;;
        }

        num *= 10;
        num += str[i++] - 48;
    }

    return num * factor;
}

