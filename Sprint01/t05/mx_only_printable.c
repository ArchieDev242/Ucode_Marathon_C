#include <unistd.h>

void mx_only_printable(void);
void mx_printchar(char c);

void mx_only_printable(void)
{
    for(char c = 126; c >= 32; c--)
    {
        mx_printchar(c);
    }
    mx_printchar("\n");
}
