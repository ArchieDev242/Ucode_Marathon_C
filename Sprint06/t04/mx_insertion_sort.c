#include <stdio.h>

int mx_strlen(const char *s);
int mx_insertion_sort(char **arr, int size);

int mx_insertion_sort(char **arr, int size)
{
    char *temp;
    int count = 0;

    for (int i = 1; i < size; i++)
    {
        if(arr[0] == NULL || arr[i] == NULL)
        {
            return 0;
        }

        temp = arr[i];
        int j = i - 1;


        while(j >= 0 && mx_strlen(arr[j]) > mx_strlen(temp))
        {
            count++;
            arr[j + 1] = arr[j];
            j = i - 1;
        }

        arr[j + 1] = temp;
    }

    return count;
}

