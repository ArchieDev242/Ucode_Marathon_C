#include "create_agent.h"

char *mx_strcpy(char *dst, const char *src)
{
    int i = 0;

    for(i = 0; src[i]; i++)
    {
        dst[i] = src[i];
    }

    dst[i] = '\0';

    return dst;
}

