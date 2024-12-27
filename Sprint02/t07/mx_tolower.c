#include <stdio.h>
#include <unistd.h>

int mx_tolower(int c);

int mx_tolower(int c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return c + ('a' - 'A');
    } else
    {
        return c;
    }
}

