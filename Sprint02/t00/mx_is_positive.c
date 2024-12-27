#include <stdio.h>

void mx_printstr(const char *s);
int mx_strlen(const char *s);
void mx_is_positive(int i);

void mx_is_positive(int i)
{
    if(i > 0)
    {
        mx_printstr("positive\n");
    } else if(i < 0)
    {
        mx_printstr("negative\n");
    } else
    {
        mx_printstr("zero\n");
    }
}

