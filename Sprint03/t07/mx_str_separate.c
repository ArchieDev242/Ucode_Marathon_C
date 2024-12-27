#include <stdio.h>

void mx_printchar(char c);
void mx_str_separate(const char *str, char delim);

void mx_str_separate(const char *str, char delim)
{

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == delim)
        {
            mx_printchar('\n');

            while(str[i] == delim) 
            {
                i++;
            }
        }

        mx_printchar(str[i]);
    }
    
    mx_printchar('\n');
}

