#include <stdio.h>
#include <stdlib.h>

char *mx_strnew(const int size);

char *mx_strnew(const int size) 
{
    if(size < 0) 
    {
        return NULL;
    }

    char *new_str = malloc(sizeof(char) * (size + 1));

    if(new_str == NULL) 
    {
        return NULL;
    }

    for(int i = 0; i < size + 1; i++) 
    {
        new_str[i] = '\0';
    }

    return new_str;
}

