double mx_pow(double n, unsigned int pow) 
{
    double result = n;

    if(!pow) 
    {
        return 1;
    }

    for(unsigned int i = 0; i < pow - 1; i++) 
    {
        result *= n;
    }

    return result;
}

