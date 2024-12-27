#include "get_address.h"

char *mx_get_address(void *p) 
{
	unsigned long adr = (unsigned long)p;
	
	char *get_adr = mx_strnew(mx_strlen(mx_nbr_to_hex(adr)) + 2);
	mx_strcpy(get_adr, "0x");
	mx_strcpy(get_adr + 2, mx_nbr_to_hex(adr));

	return get_adr;
}
	
