#include "../inc/list.h"

void mx_pop_index(t_list **list, int index) 
{
    if(!*list)
    { 
        return;
    }

    t_list *temp = *list, *helper = NULL;

    if(index < 1 || temp -> next == NULL) 
    {
        *list = temp -> next;
        free(temp);
        temp = NULL;
        return;
    }

    for(int i = 0; i < index; i++) 
    {
        if(temp -> next == NULL)
        {    
            break;
        }

        helper = temp;
        temp = temp -> next;
    }

    helper -> next = temp -> next;
    free(temp);
    temp = NULL;

    return;
}

