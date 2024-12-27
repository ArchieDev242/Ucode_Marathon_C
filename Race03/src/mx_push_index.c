#include "../inc/header.h"

void mx_push_index(t_drops_list **list, void *data, int index) 
{
    t_drops_list *new_node = mx_create_node(data);
    t_drops_list *current_node = *list;

    if(list == NULL) 
    {
        return;
    }

    if(index <= 0) 
    {
        mx_push_front(list, data);
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

    for(int i = 1; i < index && current_node->next != NULL; i++) 
    {
        current_node = current_node -> next;
    }

    t_drops_list *temp = current_node->next;
    current_node->next = new_node;
    new_node->next = temp;
}

