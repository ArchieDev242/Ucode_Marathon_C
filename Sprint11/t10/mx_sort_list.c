#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) 
{
    if(cmp == NULL || list == NULL)
    { 
        return list;
    }

    t_list *temp = list;
    int count = 0;

    while(temp) 
    {
        temp = temp -> next;
        count++;
    }

    for(int i = 0; i < count; i++) 
    {
        temp = list;

        for(int j = 0; j < count - 1; j++) 
        {
            if(cmp(temp -> data, temp -> next -> data)) 
            {
                void *data = temp -> data; 
                temp -> data = temp -> next -> data; 
                temp -> next -> data = data;     
            }

            temp = temp -> next;
        }
    }
    
    return list;
}

