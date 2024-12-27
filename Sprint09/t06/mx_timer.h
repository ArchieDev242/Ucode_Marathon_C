#include <stdio.h>
#include <time.h>

double mx_timer(void (*f)());

double mx_timer(void (*f)())
{
    if(f == NULL)
    {
        return -1;
    }

    clock_t start = clock();
    f();
    clock_t end = clock();

    return (double)((end - start) / CLOCKS_PER_SEC);
}

