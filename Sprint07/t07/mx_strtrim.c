#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char*src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);

char *mx_strtrim(const char *str)
{
    if(str == NULL)
    {
        return NULL;
    }

    int str_start = 0;
    int str_end = mx_strlen(str) - 1;
    char *new_str = NULL;

    while(mx_isspace(str[str_start]))
    {
        str_start++;
    }

    while(mx_isspace(str[str_end]))
    {
        str_end--;
    }

    int str_size = str_end - str_start + 1;
    new_str = mx_strnew(str_size);

    for(int i = 0; i < str_size; i++)
    {
        new_str[i] = str[str_start];
        str_start++;
    }

    new_str[str_size] = '\0';

    return new_str;
}

