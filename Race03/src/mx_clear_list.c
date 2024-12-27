#include "../inc/header.h"

void mx_clear_list(t_drops_list **list) 
{
    if(list == NULL) 
    {
        return;
    }

    t_drops_list *current_node = *list;

    while(current_node != NULL) 
    {
        t_drops_list *temp = current_node->next;
        free(current_node);
        current_node = temp;
    }

    *list = NULL;
}

