#include "../inc/header.h"

void mx_pop_front(t_drops_list **list) 
{
    if(list == NULL) 
    {
        return;
    }

    t_drops_list *current_node = *list;

    if(current_node == NULL) 
    {
        return;
    }

    *list = current_node->next;
    free(current_node);
}

