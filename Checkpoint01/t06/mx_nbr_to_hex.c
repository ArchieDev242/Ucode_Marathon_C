#include <stdio.h>
#include <stdlib.h>

char *mx_nbr_to_hex(unsigned long nbr);

char *mx_nbr_to_hex(unsigned long nbr)
{
    int len = 0;
    char *hex = NULL;

    for(unsigned long i = nbr; i != 0; i /= 16)
    {
        len++;
    }

    if(nbr == 0)
    { 
        len++;
    }

    hex = malloc(sizeof(char) * (len + 1));

    for(int i = len - 1; i >= 0; i--) 
    {
        hex[i] = nbr % 16 + '0';
        if(hex[i] >= 58)
        {
            hex[i] += 39;
        }
        nbr /= 16;
    }

    hex[len] = '\0';
    return hex;
}

