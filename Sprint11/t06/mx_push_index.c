#include "list.h"

void mx_push_index(t_list **list, void *data, int index) 
{
    int count = 0;

    if(!*list) 
    { 
        *list = mx_create_node(data);
        return;
    }
    
    if(index < 1) 
    {
        mx_push_front(list, data);
        return;
    } 

    t_list *temp_count = *list;

    while(temp_count) 
    {
        temp_count = temp_count -> next;
        count++;
    }

    if(index >= count) 
    {
        mx_push_back(list, data);
        return;
    }

    t_list *temp = *list, *helper = NULL;

    for(int i = 0; i < index; i++) 
    {
        helper = temp;
        temp = temp -> next;
    }

    helper -> next = mx_create_node(data);
    helper -> next -> next = temp;
}

