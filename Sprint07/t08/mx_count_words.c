#include <stdio.h>
#include <unistd.h>

int mx_count_words(const char *str, char delimiter);

int mx_count_words(const char *str, char delimiter)
{
    int words_count = 0;
    int words = 0;

    while(*str)
    {
        if(*str == delimiter)
        {
            words = 0;
        } else if(!words)
        {
            words = 1;
            words_count++;
        }
        str++;
    }
    return words_count;
}

