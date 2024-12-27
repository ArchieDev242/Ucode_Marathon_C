void mx_printchar(char c);
void mx_cube(int n);

void mx_cube(int n)
{
    if(n > 1)
    {
        mx_printchar(' ');
        for(int i=0; i < n / 2; i++)
        {
            mx_printchar(' ');
        }
        mx_printchar('+');
        for(int i=0; i < 2 * n; i++)
        {
            mx_printchar('-');
        }
        mx_printchar('+');
        mx_printchar('\n');
        for(int i=0; i < n / 2; i++)
        {
            for(int j = i; j < n / 2; j++)
            {
                mx_printchar(' ');
            }
            mx_printchar('/');
            for(int t=0; t < 2 * n; t++)
            {
                mx_printchar(' ');
            }
            mx_printchar('/');
            for(int a = 0; a < i; a++)
            {
                mx_printchar(' ');
            }
            mx_printchar('|');
            mx_printchar('\n');
        }
        
        int p = 1;
        mx_printchar('+');
        for(int i=0; i < 2 * n; i++)
        {
            mx_printchar('-');
        }
        mx_printchar('+');
        for(int i=0; i < n / 2;i++)
        {
            mx_printchar(' ');
        }
        mx_printchar('|');
        mx_printchar('\n');

        for(int i=0; i < n; i++)
        {
            mx_printchar('|');
            for(int j = 0; j < 2 * n; j++)
            {
                mx_printchar(' ');
            }
            mx_printchar('|');
            if(i < n - n / 2 - 1)
            {
                for(int j = 0; j < n / 2 ; j++)
                {
                    mx_printchar(' ');
                }
                mx_printchar('|');
            }
            else if(i == n - n / 2 - 1 )
            {
                for(int j = 0; j < n / 2 ;j++)
                {
                    mx_printchar(' ');
                }
                mx_printchar('+');
            }
            else
            {
                for(int j = 0; j < n / 2 - p ;j++)
                {
                mx_printchar(' ');
                }
                mx_printchar('/');
                 p++;
            }
            mx_printchar('\n');
        }
    
        mx_printchar('+');
        for(int i=0; i < 2 * n; i++)
        {
            mx_printchar('-');
        }
        
        mx_printchar('+');
        mx_printchar('\n');
    }
}

