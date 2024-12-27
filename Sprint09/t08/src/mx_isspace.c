#include "minilibmx.h"

bool mx_isspace(char c)
{
    if (c == ' ' || (c >= '\t' && c <= '\r') || c == '\n' || c == '\v' || c == '\f')
    {
        return true;
    } else
    {
        return false;
    }
}

