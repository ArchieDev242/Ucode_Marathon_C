#include <stdio.h>

void mx_printchar(char c);
void mx_printstr(const char *s);
char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);

int main(int argc, char *argv[])
{
    if(argc > 0 && argv[0])
    {
        char *pname = mx_strchr(argv[0], '/');

        if(pname != NULL)
        {
            pname++;
        } else 
        {
            pname = argv[0];
        }

        mx_printstr(pname);
        mx_printchar('\n');
    }
}

