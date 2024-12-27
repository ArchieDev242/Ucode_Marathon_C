#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char*src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_whitespace(const char *str);

char *mx_del_extra_whitespace(const char *str)
{
    if(str == NULL)
    {
        return NULL;
    }

    char *trim_str = mx_strtrim(str);

    if(trim_str == NULL)
    {
        return NULL;
    }

    int len = mx_strlen(trim_str);
    char *new_str = mx_strnew(len);

    if(new_str == NULL) 
    {
        mx_strdel(&trim_str);
        return NULL;
    }

    int i, j;

    for(i = 0, j = 0; trim_str[i]; ++i) 
    {
        if(!mx_isspace(trim_str[i])) 
        {
            new_str[j++] = trim_str[i];

            if(mx_isspace(trim_str[i + 1]))
            {
                new_str[j++] = ' ';
            }
        }
    }

    new_str[j] = '\0';
    mx_strdel(&trim_str);
    
    return new_str;
}

