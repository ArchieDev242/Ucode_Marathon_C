#include <stdio.h>
#include <stdlib.h>

void mx_strdel(char **str);

void mx_strdel(char **str)
{
    free(*str);
    *str = NULL;
}

