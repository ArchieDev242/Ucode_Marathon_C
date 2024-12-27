#include "list.h"

void mx_foreach_list(t_list *list, void(*f)(t_list *node)) 
{
    if(f == NULL || list == NULL)
    { 
        return;
    }

    while(list) 
    {
        f(list);
        list = list -> next;
    }
}

