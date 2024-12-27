#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_list 
{
    void *data;
    struct s_list *next;
}   t_list;


void mx_pop_back(t_list **list);

