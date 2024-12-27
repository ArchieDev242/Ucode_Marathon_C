#include "../inc/header.h"

void mx_strdel(char **str) 
{
    free(*str);
    *str = NULL;
}

