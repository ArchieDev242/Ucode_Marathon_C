#include <stdio.h>

int mx_strcmp(const char *s1, const char *s2);

int mx_strcmp(const char *s1, const char *s2) 
{
    while(*s1 != '\0' && *s2 != '\0' && *s1 == *s2) 
    {
        s1++;
        s2++;
    }
    
    return (unsigned char)*s1 - (unsigned char)*s2;
}

