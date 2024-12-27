#include "../inc/minilibmx.h"

char mx_str_reverse(char *s) 
{
    if(!s) 
    {
        return '\0';
    }

    int length = mx_strlen(s);

    for(int i = 0; i < length / 2; i++) 
    {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }

    return s[0];
}
