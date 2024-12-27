#include <stdio.h>
#include <stdlib.h>

void mx_strdel(char **str);
void mx_del_strarr(char ***arr);

void mx_del_strarr(char ***arr)
{
    if(arr == NULL || *arr == NULL)
    {
        return;
    } 

    char **result = *arr;
    
    while(*result != NULL)
    {
        mx_strdel(result);
        result++;
    }

    free(*arr);
    *arr = NULL;
}

