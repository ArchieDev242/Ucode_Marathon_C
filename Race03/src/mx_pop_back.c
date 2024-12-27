#include "../inc/header.h"

void mx_pop_back(t_drops_list **list) 
{
    if(list == NULL) 
    {
        return;
    }

    t_drops_list *current_node = *list;

    if(current_node == NULL || current_node->next == NULL) 
    {
        free(current_node);
        *list = NULL;
        return;
    }

    while(current_node -> next->next != NULL) 
    {
        current_node = current_node -> next;
    }

    free(current_node -> next);
    current_node->next = NULL;
}

