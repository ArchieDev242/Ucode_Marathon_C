#include "../inc/minilibmx.h"

char *mx_strtrim(const char *str) 
{
    if(str == NULL) 
    {
        return NULL;
    }

    int len_trim = mx_strlen(str);
    char *trimmed = mx_strnew(len_trim);

    if(trimmed == NULL) 
    {
        return NULL;
    }

    while(*str != '\0' && mx_isspace(*str)) 
    {
        str++;
    }

    while(len_trim >= 1 && mx_isspace(str[len_trim - 1])) 
    {
        len_trim--;
    }

    return mx_strncpy(trimmed, str, len_trim);
}

