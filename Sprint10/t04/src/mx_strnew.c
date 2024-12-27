#include "../inc/header.h"

char *mx_strnew(const int size) 
{
    if(size < 0) 
    {
        return NULL;
    }

    char *str = malloc(sizeof(char) * (size + 1));

    if(str == NULL) 
    {
        return NULL;
    }

    for(int i = 0; i < size + 1; i++) 
    {
        str[i] = '\0';
    }

    return str;
}

