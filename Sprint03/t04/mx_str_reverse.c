#include <stdio.h>
#include <unistd.h>

void mx_swap_char(char *s1, char *s2);
int mx_strlen(const char *s);
void mx_str_reverse(char *s);

void mx_str_reverse(char *s)
{
    int text_length = mx_strlen(s);
    int text_start = 0;
    int text_end = text_length - 1;

    while(text_start < text_end)
    {
        mx_swap_char(&s[text_start], &s[text_end]);
        text_start++;
        text_end--;
    }
}

