#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
void mx_printchar(char c);
void mx_printint(int n);

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        return 0;
    }

    for(int i = 1; i < argc; i++) 
    {
        unsigned int num1 = mx_atoi(argv[i]);
        for(int j = 31; j >= 0; j--) 
        {
            unsigned int num2 = 1u << j;
            char digit;
            
            if(num1 & num2)
            {
                digit = '1';
            } else
            {
                digit = '0';
            }
            mx_printchar(digit);
        }
        mx_printchar('\n');
    }
}

