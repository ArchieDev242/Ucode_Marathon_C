#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct  s_list 
{
    void *data;
    struct s_list *next;
}   t_list;


t_list *mx_sort_list(t_list *list, bool(*cmp)(void *a, void *b));

