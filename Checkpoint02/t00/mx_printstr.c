#include <stdio.h>
#include <unistd.h>

void mx_printstr(const char *s);

void mx_printstr(const char *s) 
{
	unsigned long strlen = 0;

    for(; s[strlen] != '\0'; strlen++)
    {
        write(1, s, strlen);
    }
}

