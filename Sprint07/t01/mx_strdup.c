#include <stdio.h>
#include <stdlib.h>

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);

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

