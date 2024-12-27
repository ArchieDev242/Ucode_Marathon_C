#include "../inc/header.h"

char *mx_strjoin(char const *s1, char const *s2) 
{
    if(s1 == NULL && s2 == NULL) 
    {
        return NULL;
    }

    if(s1 == NULL) 
    {
        return mx_strdup(s2);
    }

    if(s2 == NULL) 
    {
        return mx_strdup(s1);
    }
    
    char *res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    mx_strcpy(res, s1);
    mx_strcat(res, s2);

    return res;
}

