#include <stdio.h>
#include <stdlib.h>

char *mx_strdup(const char *str);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);

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

char *mx_strdup(const char *str)
{
    char *str_new = mx_strnew(mx_strlen(str));

    if(str == NULL)
    {
        return NULL;
    }

    mx_strcpy(str_new, str);

    return str_new;
}

