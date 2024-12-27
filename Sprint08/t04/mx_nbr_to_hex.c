#include "get_address.h"

char *mx_nbr_to_hex(unsigned long nbr) 
{
	unsigned long temp = nbr;
	int count = 0;

	while(temp) 
	{
		temp /= 16;
		count++;
	}

	char *result = mx_strnew(count);

	for(int j = count - 1; j >= 0; j--) 
	{
		int n = nbr % 16;

		if(n < 10) 
		{
			result[j] = n + 48;
		} else 
		{
			result[j] = n + 87;
		}
		
		nbr /= 16;
	}

	return result;
} 

