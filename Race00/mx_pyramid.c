void mx_printchar(char c);
void mx_pyramid(int n);

void mx_pyramid(int n)
{
    if(n > 1 && n % 2 == 0)
    {
        int a = 1;
        int b = 1;

        for(int i = 1; i < n; i++)
        {
            mx_printchar(' ');
        }

        mx_printchar('/');
        mx_printchar('\\');
        mx_printchar('\n');

        for(int i = 2; i < n; i++)
        {
            if(i == n / 2 + 1)
            {
                b--;
            }
            for(int j = i ; j < n; j++)
            {
                mx_printchar(' ');
            }

            mx_printchar('/');

            for(int j = 0; j < a; j++)
            {
                mx_printchar(' ');
            }

            mx_printchar('\\');

            if(i <= n / 2)
            {
                for(int j = 0; j < b; j++)
                {
                    mx_printchar(' ');
                }
                mx_printchar('\\');
                b++;
            } else
            {
                for(int j = 0; j < b; j++)
                {
                    mx_printchar(' ');
                }
                mx_printchar('|');
                b--;
            }

            a = a + 2;
            mx_printchar('\n');
        }

        mx_printchar('/');

        for(int i = 0; i < 2 * n - 3; i++)
        {
            mx_printchar('_');
        }
        
        mx_printchar('\\');
        mx_printchar('|');
        mx_printchar('\n');

    }
}

