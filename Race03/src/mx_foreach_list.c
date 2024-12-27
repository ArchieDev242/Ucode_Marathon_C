#include "../inc/header.h"

void mx_foreach_list(t_drops_list *list, void (*f)(t_drops_list *node))
 {
    if(list == NULL || f == NULL) 
    {
        return;
    }

    t_drops_list *current_node = list;

    while(current_node != NULL) 
    {
        t_drops_list *temp = current_node->next;
        f(current_node);
        current_node = temp;
    }
}

