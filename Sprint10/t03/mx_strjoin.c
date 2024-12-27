#include "file_to_str.h"

char *mx_strjoin(const char *s1, const char *s2)
{
    char *res = NULL;

    if((!s1) && (!s2))
    {
        return NULL;
    } 

    if(!s1)
    {
        return mx_strdup(s2);
    }

    if(!s2)
    {
        return mx_strdup(s1);
    }

    res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(res, s1);
    mx_strcat(res, s2);

    return res;
}

