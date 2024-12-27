#include <stdio.h>
#include <unistd.h>

int mx_strcmp(const char *s1, const char *s2);
int mx_binary_search(char **arr, int size, const char *s, int *count);

int mx_binary_search(char **arr, int size, const char *s, int *count)
{
    int first_part = 0;
    int last_part = size - 1;

    while(first_part <= last_part)
    {
        int middle_part = first_part + (last_part - first_part) / 2;
        (*count)++;

        if(mx_strcmp(arr[middle_part], s) == 0)
        {
            return middle_part;
        } else if(mx_strcmp(arr[middle_part], s < 0))
        {
            first_part = middle_part + 1;
        } else
        {
            last_part = middle_part - 1;
        }
    }  

    *count = 0;
    return -1;
}

