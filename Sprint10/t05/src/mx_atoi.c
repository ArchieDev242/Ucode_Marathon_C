#include "../inc/header.h"

int mx_atoi(const char *str) 
{
    int i = 0;
    int count = 0;

    if(str[0] == '-') 
    {
        count = -1;
        i++;
    }

    if(str[0] == '+') 
    {
    	count = 1;
    	i++;
    }

    int number = 0;

    for(int d = i; str[d] != '\0'; d++) 
    {
        if(mx_isdigit(str[d])) 
        {
            number = number * 10 + str[d] - '0';
        } else {
            break;
        }

        if(mx_isspace(str[d])) 
        {
            break;         
        }    
    }

    return (count == -1) ? number *= -1 : number;
}

