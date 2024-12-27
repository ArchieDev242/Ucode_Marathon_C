#include "../inc/header.h"

void mx_push_front(t_drops_list **list, void *data) 
{
    t_drops_list *new_node = mx_create_node(data);

    if(list == NULL) 
    {
        return;
    }

    if(new_node == NULL) 
    {
        return;
    }

    new_node -> next = *list;
    *list = new_node;
}

