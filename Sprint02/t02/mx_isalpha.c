#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool mx_isalpha(int c);

bool mx_isalpha(int c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
    {
        return true;
    } else
    {
        return false;
    }
}

