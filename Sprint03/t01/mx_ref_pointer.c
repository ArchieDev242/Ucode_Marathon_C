#include <stdio.h>
#include <string.h>

void mx_ref_pointer(int i, int ******ptr);

void mx_ref_pointer(int i, int ******ptr)
{
    ******ptr = i;
}

