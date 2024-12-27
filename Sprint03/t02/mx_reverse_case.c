#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool mx_islower(int c);
bool mx_isupper(int c);
int mx_tolower(int c);
int mx_toupper(int c);
void mx_reverse_case(char *s);

void mx_reverse_case(char *s)
{
    for(int i = 0; s[i] != '\0'; i++) 
    {
        if(mx_isupper(s[i])) 
        {
            s[i] = mx_tolower(s[i]);
        } else if (mx_islower(s[i])) 
        {
            s[i] = mx_toupper(s[i]);
        }
    }
}

