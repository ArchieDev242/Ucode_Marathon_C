#include <unistd.h>

void mx_hexadecimal(void);
void mx_printchar(char c);

void mx_hexadecimal(void)
{
    for(char c = '0'; c <= 'F'; ++c) 
    {
        if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) 
        {
            mx_printchar(c);
        }
    }
    mx_printchar("\n");
}
