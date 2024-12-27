#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        return 0;
    }

    char *temp;

    for(int i = 1; i < argc; i++)
    {
        temp = argv[i];

        while(*temp)
        {
            write(1, temp++, 1);
        }
        
        write(1, "\n", 1);
    }

    return 0;
}

