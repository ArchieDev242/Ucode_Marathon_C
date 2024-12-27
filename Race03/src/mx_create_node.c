#include "../inc/header.h"

t_drops_list *mx_create_node(void *data) 
{
    t_drops_list *list = malloc(sizeof(t_drops_list));

    if(list == NULL)
    {
        return NULL;
    }

    list -> data = data;
    list -> next = NULL;

    return list;
}

