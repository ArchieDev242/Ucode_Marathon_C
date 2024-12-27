#include <stdio.h>

char *mx_strchr(const char *s, int c);

char *mx_strchr(const char *s, int c)
{
    while(*s != '\0')
    {
        if(*s == c)
        {
            return (char*) s;
        }
        s++;
    }

    if(c == '\0')
    {
        return (char*) s;
    }
    return NULL;
}

