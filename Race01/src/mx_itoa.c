#include "../inc/minilibmx.h"

int number_length(int number) 
{
	int num_len = 0;

	while(number) 
	{
		number /= 10;
		num_len++;
	}

	return num_len;
}

char *mx_itoa(int number) 
{
	int num_len = number_length(number);
	int temp_num = number;

	char *result = mx_strnew(num_len);

    if(result == NULL) 
	{
        return NULL;
    }

	if(number == 0) 
	{
		return mx_strcpy(result, "0");
    }

	if(number == -2147483648) 
	{
		return mx_strcpy(result, "-2147483648");
    }

	temp_num = number;

	for(int i = 0; i < num_len; i++) 
	{
		if(temp_num < 0) 
		{
			result[num_len] = '-';
			temp_num = -temp_num;
		}

		result[i] = (temp_num % 10) + '0';
		temp_num /= 10;
	}

	mx_str_reverse(result);

	return result;
}

