#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

unsigned long mx_hex_to_nbr(const char *hex);
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);

bool mx_isalpha(int c)
{
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
    {
        return true;
    } else
    {
        return false;
    }
}

bool mx_isdigit(int c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    } else 
    {
        return false;
    }
}

bool mx_islower(int c)
{
    if(c >= 'a' && c <= 'z')
    {
        return true;
    } else
    {
        return false;
    }
}

bool mx_isupper(int c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return true;
    } else
    {
        return false;
    }
}

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

