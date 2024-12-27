#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool mx_islower(int c);

bool mx_islower(int c)
{
    if(c >= 'a' && c <= 'z')
    {
        return true;
    } else
    {
        return false;
    }
}

