#include "hex_to_nbr.h"

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

