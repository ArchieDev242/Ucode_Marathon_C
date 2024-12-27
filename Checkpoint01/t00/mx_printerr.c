#include <stdio.h>
#include <unistd.h>

void mx_printerr(const char *s);

void mx_printerr(const char *s)
{
    int i = 0;

    while(s[i]!= '\0')
    {
        write(2, &s[i], 1);
        i++;
    }
}

