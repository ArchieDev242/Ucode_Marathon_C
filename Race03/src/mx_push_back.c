#include "../inc/header.h"

void mx_push_back(t_drops_list **list, void *data) 
{

    t_drops_list *new_node = mx_create_node(data);
    t_drops_list *current_node = *list;

    if(list == NULL) 
    {
        return;
    }

    if(new_node == NULL)
    {
        return;
    }

    if(current_node == NULL) 
    {
        *list = new_node;
        return;
    }

    while (current_node -> next != NULL) 
    {
        current_node = current_node->next;
    }

    current_node -> next = new_node;
}

