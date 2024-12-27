#include <stdio.h>
#include <unistd.h>

char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

char *mx_strstr(const char *s1, const char *s2)
{
    while(*s1 != '\0')
    {
        if (mx_strncmp(s1, s2, mx_strlen(s2)) == 0)
            return (char *)s1;
        s1++;

        while(*s2 != '\0' && *s1 == *s2)
        {
            s1++;
            s2++;
        }

        if(*s2 == '\0')
        {
            return (char *)s1;
        }

        s1++;
    }

    return NULL;
}

