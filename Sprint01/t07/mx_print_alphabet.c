#include <unistd.h>

void mx_print_alphabet(void);
void mx_printchar(char c);

void mx_print_alphabet(void)
{
    for(char c = 'A'; c <= 'Z'; c++)
    {
        mx_printchar(c);
        mx_printchar(c + 32);
    }
    mx_printchar("\n");
}
