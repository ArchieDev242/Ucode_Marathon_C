#include <stdio.h>
#include <unistd.h>

int mx_popular_int(const int *arr, int size);

int mx_popular_int(const int *arr, int size)
{
    int popular = arr[0];
    int count = 0;

    for(int i = 0; i < size - 1; i++)
    {
        int temp = arr[i];
        int max_count = 0;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] == temp)
            {
                max_count++;
            }
        }
        if(max_count > count)
        {
            count = max_count;
            popular = temp;
        }
    }
    return popular;
}

