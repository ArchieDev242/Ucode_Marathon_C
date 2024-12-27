#include <unistd.h>
#include <fcntl.h>

int mx_strlen(const char *);
void mx_printstr(const char *);
void mx_printerr(const char *);
int mx_file_length(int);

int mx_strlen(const char *s)
{
    int length = 0;

    while(s[length] != '\0')
    {
        length++;
    }

    return length;
}

void mx_printstr(const char *s) 
{
    write(1, s, mx_strlen(s));
}

void mx_printerr(const char *s) 
{
    write(2, s, mx_strlen(s));
}

int mx_file_length(int file) 
{
    int len = 0;

    char c;

    while(read(file, &c, 1) != 0)
    {
        len++;
    }

    return len;
}

int main(int argc, char *argv[]) 
{
    if (argc == 2) 
    {
        int file = open(argv[1], O_RDONLY);

        if(file < 0) 
        {
            mx_printerr("error\n");
            close(file);
            return 0;
        }

        int len = mx_file_length(file);

        close(file);

        file = open(argv[1], O_RDONLY);

        char text[len];
        
        read(file, text, len);
        text[len] = '\0';
        mx_printstr(text);
        
        close(file);
    } else 
    {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [file_path]\n");

        return 0;
    }

}

