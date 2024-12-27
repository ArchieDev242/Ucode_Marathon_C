#include <stdio.h>

void mx_swap_char(char *s1, char *s2);

void mx_swap_char(char *s1, char *s2) 
{
    char swap = *s1;
    *s1 = *s2;
    *s2 = swap;
}

