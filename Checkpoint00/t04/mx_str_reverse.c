#include <stdio.h>
#include <unistd.h>

void mx_str_reverse(char *s);

void mx_str_reverse(char *s)
{
    char *start = s;
    char *end = s;

    while(*end != '\0')
    {
        end++;
    }
    end--;

    while(start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

