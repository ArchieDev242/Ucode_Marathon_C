#include "../inc/header.h"

int main(int argc, char *argv[]) 
{
    if(argc != 2) 
    {
        mx_printerr("usage: ./read_file [file_path]\n");
        return -1;
    }
    
    ssize_t size;
    
    int input_file = open(argv[1], O_RDONLY);
    
    if(input_file < 0) 
    {
        mx_printerr("error\n");
        close(input_file);
        return -1;
    }
    
    char buffer;

    while((size = read(input_file, &buffer, 1))) 
    {
        if(size == -1) 
        {
            mx_printerr("error\n");
            close(input_file);
            return -1; 
        }

        write(1, &buffer, 1);
    }
    
    close(input_file);
    return 0;
}


