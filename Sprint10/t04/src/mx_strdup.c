#include "../inc/header.h"

char *mx_strdup(const char *str) 
{
    char *new_str = mx_strnew(mx_strlen(str));
    mx_strcpy(new_str, str);
    return new_str;
}

