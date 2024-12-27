#include "../inc/header.h"

void mx_pop_index(t_drops_list **list, int index)
{
    if(list == NULL) 
    {
        return;
    }

    if(index <= 0)
    {
        mx_pop_front(list);
        return;
    }

    t_drops_list *current_node = *list;

    if(current_node == NULL) 
    {
        return;
    }

    if(current_node -> next == NULL) 
    {
        free(current_node);
        *list = NULL;
        return;
    }

    for(int i = 1; i < index && current_node->next->next != NULL; i++)
    {
        current_node = current_node -> next;
    }

    t_drops_list *temp = current_node -> next -> next;
    free(current_node -> next);
    current_node->next = temp;
}

