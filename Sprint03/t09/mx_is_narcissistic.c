#include <stdio.h>
#include <stdbool.h>

double mx_pow(double n, unsigned int pow);
bool mx_is_narcissistic(int num);

bool mx_is_narcissistic(int num)
{
    if(num < 0)
    {
        return false;
    }

    int count_digits = 0;
    int temp_num = num;
    int sum = 0;
    int digit;

    while(temp_num != 0)
    {
        count_digits++;
        temp_num /= 10;
    }

    temp_num = num;

    while(temp_num != 0)
    {
        digit = temp_num % 10;
        sum += mx_pow(digit, count_digits);
        temp_num /= 10;
    }

    if(sum == num)
    {
        return true;
    } else
    {
        return false;
    }
}

