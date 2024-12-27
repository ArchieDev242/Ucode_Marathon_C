#include "hex_to_nbr.h"

unsigned long mx_hex_to_nbr(const char *hex) 
{
	int i = 0;
	unsigned long result = 0;

	if(hex == 0) 
	{
		return 0;
	}

	while(hex[i]!='\0') 
	{
		int number = 0; 

		if(mx_isdigit(hex[i])) 
		{
			number = hex[i] - 48;
		} else if(mx_islower(hex[i])) 
		{
			number = hex[i] - 97 + 10;
		} else if(mx_isupper(hex[i])) 
		{
			number = hex[i] - 65 + 10;
		}
		i++;

		if(number == -1) 
		{
			return 0;
		}

		result = (result * 16) + number;
	}

	return result;
}

