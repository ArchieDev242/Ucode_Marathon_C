#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
int mx_selection_sort(char **arr, int size);

int mx_selection_sort(char **arr, int size)
{
    int pos_index = 0;
	int count = 0;
	char *temp;

    for(int i = 0; i < size - 1; i++)
    {
        if(arr[i] == NULL)
        {
            return 0;
        }
        
        pos_index = i;

        for(int j = i + 1; j < size; j++)
        {
            if(mx_strlen(arr[pos_index]) == mx_strlen(arr[j]) && mx_strcmp(arr[pos_index], arr[j]) > 0)
            {
                pos_index = j;
            } else if(mx_strlen(arr[pos_index]) > mx_strlen(arr[j]))
            {
                pos_index = j;
            }
        }

        if(pos_index != i)
        {
            temp = arr[i];
            arr[i] = arr[pos_index];
            arr[pos_index] = temp;
            count++;
        }
    }

    return count;
}

