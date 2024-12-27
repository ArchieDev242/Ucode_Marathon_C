#include <stdio.h>
#include <unistd.h>

int mx_strncmp(const char *s1, const char *s2, int n);

int mx_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;
    
    while(s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
        if(s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    if(i == n)
    {
        return 0;
    }

    return s1[i] - s2[i]; 
}

