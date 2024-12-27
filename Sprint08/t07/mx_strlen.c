#include "create_agent.h"

int mx_strlen(const char *s)
{
    int length = 0;

    while(s[length] != '\0')
    {
        length++;
    }

    return length;
}

