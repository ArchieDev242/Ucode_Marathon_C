#include "../inc/header.h"

void print_counts(int lines_count, int words_count, int bytes_count, char *file_name) 
{
    mx_printchar('\t');
    mx_printint(lines_count);
    mx_printchar('\t');
    mx_printint(words_count);
    mx_printchar('\t');
    mx_printint(bytes_count);
    
    if(file_name) 
    {
        mx_printchar(' ');
        mx_printstr(file_name);
    }

    mx_printchar('\n');
}

int main(int argc, char *argv[]) 
{
    if(argc == 1) 
    {
        char *str = mx_strnew(1), *c = mx_strnew(1);
        int lines_count = 0, words_count = 0, bytes_count = 0;
        
        while(read(0, c, 1)) 
        {
            if(*c == '\n') 
            {
                lines_count++;
            }

            str = mx_strjoin(str, c);
            
            bytes_count++;
        }
        
        words_count = mx_count_words(str);
        
        print_counts(lines_count, words_count, bytes_count, NULL);
        
        exit(EXIT_SUCCESS);
    }
    
    int total_words_count = 0;
    int total_lines_count = 0;
    int total_bytes_count = 0;

    for(int i = 1; i < argc; i++) 
    {
        int src = open(argv[i], O_RDWR);

        if(src == -1) 
        {
            mx_printerr("mx_wc: ");
            mx_printerr(argv[i]);
            mx_printerr(": ");

            switch (errno) 
            {
                case EISDIR:
                    mx_printerr("read: ");
                    break;
                case ENOENT:
                    mx_printerr("open: ");
                    break;
            }

            mx_printerr(strerror(errno));
            mx_printerr("\n");
        } else 
        {
            char *str = mx_strnew(1), *c = mx_strnew(1);
            int lines_count = 0, words_count = 0, bytes_count = 0;
            
            while(read(src, c, 1)) 
            {
                if(*c == '\n') 
                {
                    lines_count++;
                }
                
                str = mx_strjoin(str, c);
                
                bytes_count++;
            }
            
            words_count = mx_count_words(str);
            
            total_words_count += words_count;
            total_lines_count += lines_count;
            total_bytes_count += bytes_count;
            
            print_counts(lines_count, words_count, bytes_count, argv[i]);
            
            close(src);
        }
    }
    
    if(total_bytes_count && argc > 2) 
    {
        print_counts(total_lines_count, total_words_count, total_bytes_count, "total");
    }

    return 0;
    
}

