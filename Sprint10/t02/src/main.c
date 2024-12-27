#include "../inc/header.h"

int main(int argc, char *argv[]) 
{
    int status = 0;
    char buff;

    if(argc < 2) 
    {
        while(read(STDIN_FILENO, &buff, 1)) 
        {
            write(STDOUT_FILENO, &buff, 1);
        }
    }
    
    for(int i = 1; i < argc; i++) 
    {
        int fd = (*(argv[i]) == '-' ? STDIN_FILENO : open(argv[i], O_RDONLY));

        if(fd == -1) 
        {
            mx_printerr("mx_cat: ");
            mx_printerr(argv[i]);
            mx_printerr(": ");
            mx_printerr(strerror(errno));
            mx_printerr("\n");
            status = 1;
            continue;
        }

        while((read(fd, &buff, 1))) 
        {
            write(STDOUT_FILENO, &buff, 1);
        }

        close(fd);
    }

    return status;
}

