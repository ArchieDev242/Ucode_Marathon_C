#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) 
{
	if(src == NULL || src -> size == 0 || src -> arr == NULL) 
	{
		return NULL;
	}

	for(int i = 0; i < src -> size; i++) 
	{
    	for(int j = i + 1; j < src -> size; j++) 
		{
        	if(src -> arr[i] == src -> arr[j]) 
			{
            	for(int k = j; k < src -> size - 1; k++) 
				{  
                    src -> arr[k] = src -> arr[k + 1];  
                }
				
                src -> size--;
                j--;      
            }  
        }  
    }

    t_intarr *new_arr = malloc(sizeof(t_intarr));
	new_arr -> size = src -> size;
	int *int_arr = mx_copy_int_arr(src -> arr, src -> size);
	new_arr -> arr = int_arr;  

	return new_arr;
}

