#include <stdio.h>
#include <stdlib.h>

char *mx_strdup(const char *str);

char *mx_strdup(const char *str)
{
    const char *temp = str;
    int str_size = 0;

    if(str_size < 0)
    {
        return NULL;
    }

    while(*temp++)
    {
        str_size++;
    }

    char *dst = (char *)malloc(str_size + 1);

    if(dst == NULL)
    {
        return NULL;
    }

    for(int i = 0; i <= str_size; i++)
    {
        dst[i] = '\0';
    }

    char *ptr = dst;

    for(int i = 0; (dst[i] = str[i]) != '\0'; i++);

    return ptr;
}

