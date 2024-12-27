#include <stdio.h>
#include <stdbool.h>

bool mx_is_odd(int value);

bool mx_is_odd(int value)
{
    if(value % 2 == 1)
    {
        return true;
    } else 
    {
        return false;
    }
}

