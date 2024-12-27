#include "file_to_str.h"

int mx_strlen(const char *s)
{
    int length = 0;

    while(s[length] != '\0')
    {
        length++;
    }

    return length;
}


