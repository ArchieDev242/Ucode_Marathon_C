#include "create_agent.h"

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

