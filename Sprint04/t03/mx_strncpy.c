#include <stdio.h>

char *mx_strncpy(char *dst, const char*src, int len);

char *mx_strncpy(char *dst, const char*src, int len)
{
    int i = 0;

    if(len < 0)
    {
        return 0;
    }

    while(i < len && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }

    while(i < len)
    {
        dst[i] = '\0';
        i++;
    }
    
    return dst;
}

