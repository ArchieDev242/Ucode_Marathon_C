#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool mx_isupper(int c);

bool mx_isupper(int c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return true;
    } else
    {
        return false;
    }
}

