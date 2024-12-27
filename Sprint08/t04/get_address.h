#ifndef GET_ADDRESS_H
#define GET_ADDRESS_H

#include <stdlib.h>
#include <stdio.h>

char *mx_nbr_to_hex(unsigned long nbr);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);

char *mx_get_address(void *p);

#endif

