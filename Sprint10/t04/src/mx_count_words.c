#include "../inc/header.h"

int mx_count_words(const char *str) 
{
    bool check = 0;
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++) 
    {
        if(mx_isspace(str[i])) 
        {
            check = false;
        } else if(!check) 
        {
            check = true;
            count++;
        }
    }

    return count;
}

