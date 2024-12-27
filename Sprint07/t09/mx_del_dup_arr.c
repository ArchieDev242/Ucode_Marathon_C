#include <stdio.h>
#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);
int *mx_del_dup_arr(int *src, int src_size, int *dst_size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size)
{
    if(src == NULL || src_size <= 0)
    {
        *dst_size = 0;
        return NULL;
    }

    int *result = mx_copy_int_arr(src, *dst_size);
    int count = 0;
    
    if(result == NULL)
    {
        *dst_size = 0;
        return NULL;
    }

    for(int i = 0; i < src_size; i++)
    {
        int j;

        for(j = 0; j < count; j++)
        {
            if(result[j] == src[i])
            {
                break;
            }
        }

        if(j == count)
        {
            result[count++] = src[i];
        }
    }

    *dst_size = count;

    return result;
}

