#include <stdio.h>
#include <unistd.h>

int mx_toupper(int c);

int mx_toupper(int c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - ('a' - 'A');
    } else
    {
        return c;
    }
}

