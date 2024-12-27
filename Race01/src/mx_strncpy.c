#include "../inc/minilibmx.h"

char *mx_strncpy(char *dst, const char *src, int len) 
{
    int i = 0;

    while(src[i] != '\0') 
    {
        if(i >= len) 
        {
            return dst;
        }

        dst[i] = src[i];
        i++;
    }

    while(i < len) 
    {
        dst[i++] = '\0';
    }

    return dst;
}

