#include "../inc/header.h"

void mx_strdel(char **str) 
{
    if(*str) 
    {
        free(*str);
        *str = NULL;
    }
}

