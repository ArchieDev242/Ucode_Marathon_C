#include "../inc/header.h"

int main(int argc, char *argv[]) 
{
    if(argc != 3) 
    {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return -1;
    }
    
    int input_file = open(argv[1], O_RDONLY);
    
    if(input_file < 0) 
    {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        close(input_file);
        return -1;
    }
    
    int output_file = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
    char buffer;

    while((read(input_file, &buffer, 1))) 
    {
        write(output_file, &buffer, 1);
    }

    close(output_file);
    close(input_file);

    return 0;
}


