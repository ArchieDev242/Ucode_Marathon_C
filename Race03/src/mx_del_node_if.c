#include "../inc/header.h"

void mx_del_node_if(t_drops_list **list, void *del_data, bool (*cmp)(void *a, void *b)) 
{
    if(list == NULL) 
    {
        return;
    }

    t_drops_list *previous_node = NULL;
    t_drops_list *current_node = *list;

    while(current_node != NULL) 
    {
        t_drops_list *temp = current_node->next;

        if(cmp(current_node -> data, del_data)) 
        {
            if(previous_node == NULL) 
            {
                *list = current_node -> next;
            }else 
            {
                previous_node -> next = current_node -> next;
            }

            free(current_node);
        }else 
        {
            previous_node = current_node;
        }

        current_node = temp;
    }
}

