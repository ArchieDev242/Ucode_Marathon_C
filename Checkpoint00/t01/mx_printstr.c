#include <stdio.h>
#include <unistd.h>

void mx_printstr(const char *s);

void mx_printstr(const char *s)
{
    while(*s != '\0')
    {
        write(1, s, 1);
        s++;
    }
}

