#include "../inc/header.h"

char *mx_strcat(char *s1, const char *s2)
{
    int num1 = mx_strlen(s1);
    int num2 = mx_strlen(s2);

    for(int i = 0; i < num2; i++)
    {
        s1[num1 + i] = s2[i];
    }

    s1[num1 + num2] = '\0';

    return s1;
}

