#include "../inc/part_of_the_matrix.h"

void mx_print_equation(char *operand1, char *operation, char *operand2, char *result) 
{
    if(*operation == '?') 
    {
        mx_print_equation(operand1, "+", operand2, result);
        mx_print_equation(operand1, "-", operand2, result);
        mx_print_equation(operand1, "*", operand2, result);
        mx_print_equation(operand1, "/", operand2, result);
        return;
    }

    int operand1_len = mx_strlen(operand1);
	int operand2_len = mx_strlen(operand2);
	int result_len = mx_strlen(result);
	
    bool operand1_neg = false;
	bool operand2_neg = false;
	bool result_neg = false;

    if(*operand1 == '-') 
    {
        operand1_neg = true;
        operand1++;
        operand1_len--;
    }

    if(*operand2 == '-') 
    {
        operand2_neg = true;
        operand2++;
        operand2_len--;
    }

    if(*result == '-') 
    {
        result_neg = true;
        result++;
        result_len--;
    }

    int operand1_int = mx_atoi_ruthless(operand1);
	int operand2_int = mx_atoi_ruthless(operand2);
	int result_int = mx_atoi_ruthless(result);

    for(long long i = operand1_int; i < mx_pow(10, operand1_len); i++) 
    {
        char *i_ascii = mx_itoa(i);
        int i_len = mx_strlen(i_ascii);
        bool i_is_correct = true;

        for(int j = 0; j < operand1_len - i_len; j++) 
        {
            if(mx_isdigit(operand1[j]) && operand1[j] != '0')
            {
                i_is_correct = false;
                break;
            }
        }

        if(!i_is_correct) 
        {
            mx_strdel(&i_ascii);
            continue;
        }

        for(int j = operand1_len - i_len, k = 0; j < operand1_len; j++, k++) 
        {
            if(operand1[j] != '?' && operand1[j] != i_ascii[k]) 
            {
                i_is_correct = false;
                break;
            }
        }

        mx_strdel(&i_ascii);

        if(!i_is_correct) 
        {
            continue;
        }

        for(long long j = operand2_int; j < mx_pow(10, operand2_len); j++) 
        {
            char *j_ascii = mx_itoa(j);
            int j_len = mx_strlen(j_ascii);
            bool j_is_correct = true;

            for(int p = 0; p < operand2_len - j_len; p++) 
            {
                if (mx_isdigit(operand2[p]) && operand2[p] != '0') 
                {
                    j_is_correct = false;
                    break;
                }
            }

            if(!j_is_correct) 
            {
                mx_strdel(&j_ascii);
                continue;
            }

            for(int p = operand2_len - j_len, j_ascii_i = 0; p < operand2_len; p++, j_ascii_i++) 
            {
                if(operand2[p] != '?' && operand2[p] != j_ascii[j_ascii_i]) 
                {
                    j_is_correct = false;
                    break;
                }
            }

            mx_strdel(&j_ascii);

            if(!j_is_correct) 
            {
                continue;
            }

            for(long long k = result_int; k < mx_pow(10, result_len); k++) 
            {
                char *k_ascii = mx_itoa(k);
                int k_len = mx_strlen(k_ascii);
                bool k_is_correct = true;

                for(int n = 0; n < result_len - k_len; n++) 
                {
                    if(mx_isdigit(result[n]) && result[n] != '0') 
                    {
                        k_is_correct = false;
                        break;
                    }
                }

                if(!k_is_correct) 
                {
                    mx_strdel(&k_ascii);
                    continue;
                }

                for(int n = result_len - k_len, k_ascii_i = 0; n < result_len; n++, k_ascii_i++) 
                {
                    if(result[n] != '?' && result[n] != k_ascii[k_ascii_i]) 
                    {
                        k_is_correct = false;
                        break;
                    }
                }

                mx_strdel(&k_ascii);

                if(!k_is_correct) 
                {
                    continue;
                }

                i = (operand1_neg ? -i : i);
                j = (operand2_neg ? -j : j);
                k = (result_neg ? -k : k);

                switch(*operation) 
                {
                    case '+':
                        if (i + j == k) {
                            mx_printint(i);
                            mx_printstr(" + ");
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(k);
                            mx_printchar('\n');
                        }
                        break;
                    case '-':
                        if (i - j == k) {
                            mx_printint(i);
                            mx_printstr(" - ");
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(k);
                            mx_printchar('\n');
                        }
                        break;
                    case '*':
                        if (i * j == k) {
                            mx_printint(i);
                            mx_printstr(" * ");
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(k);
                            mx_printchar('\n');
                        }
                        break;
                    case '/':
                        if (j != 0 && i / j == k) {
                            mx_printint(i);
                            mx_printstr(" / ");
                            mx_printint(j);
                            mx_printstr(" = ");
                            mx_printint(k);
                            mx_printchar('\n');
                        }
                        break;
                }

                i = (operand1_neg ? -i : i);
                j = (operand2_neg ? -j : j);
                k = (result_neg ? -k : k);

                if(result_int > 0) 
                {
                    break;
                }
            }

            if(operand2_int > 0) 
            {
                break;
            }
        }

        if(operand1_int > 0) 
        {
            break;
        }
    }

    operand1 -= operand1_neg;
    operand2 -= operand2_neg;
    result -= result_neg;
}

void mx_handle_error(enum e_error type, char *value) 
{

    switch (type) 
    {
        case INVALID_OPERATION:
            mx_printerr("Invalid operation: ");
            break;
        case INVALID_OPERAND:
            mx_printerr("Invalid operand: ");
            break;
        case INVALID_RESULT:
            mx_printerr("Invalid result: ");
            break;
    }

    mx_printerr(value);
    mx_printerr("\n");
}

bool mx_parse_number(char *value) 
{
    char *trimmed = mx_strtrim(value);

    if(!mx_strlen(trimmed))
    {
        mx_strdel(&trimmed);
        return false;
    }

    for(int i = 0; trimmed[i] != '\0'; i++)
    {
        if((!mx_isdigit(trimmed[i]) && trimmed[i] != '?') && !(trimmed[i] == '-' && i == 0))
        {
            mx_strdel(&trimmed);
            return false;
        }
    }

    mx_strdel(&trimmed);

    return true;
}

bool mx_parse_operation(char *value) 
{
    char *trimmed = mx_strtrim(value);

    if(mx_strlen(trimmed) == 0)
    {
        mx_strdel(&trimmed);
        return false;
    }

    int question_mark_count = 0;

    for(int i = 0; trimmed[i] != '\0'; i++)
    {
        if(question_mark_count > 1) 
        {
            mx_strdel(&trimmed);
            return false;
        }

        if(trimmed[i] == '?') 
        {
            question_mark_count++;
        }
    }

    bool result = !(mx_strcmp(trimmed, "?") && mx_strcmp(trimmed, "+") && mx_strcmp(trimmed, "-") && mx_strcmp(trimmed, "*") && mx_strcmp(trimmed,"/"));

    mx_strdel(&trimmed);

    return result;
}

void mx_parse_arguments(char **operand1, char **operation, char **operand2, char **result) 
{
    if(!mx_parse_operation(*operation)) 
    {
        mx_handle_error(INVALID_OPERATION, *operation);
        exit(EXIT_FAILURE);
    }

    if(!mx_parse_number(*operand1)) 
    {
        mx_handle_error(INVALID_OPERAND, *operand1);
        exit(EXIT_FAILURE);
    }

    if(!mx_parse_number(*operand2)) 
    {
        mx_handle_error(INVALID_OPERAND, *operand2);
        exit(EXIT_FAILURE);
    }

    if(!mx_parse_number(*result)) 
    {
        mx_handle_error(INVALID_RESULT, *result);
        exit(EXIT_FAILURE);
    }

    *operand1 = mx_strtrim(*operand1);
    *operation = mx_strtrim(*operation);
    *operand2 = mx_strtrim(*operand2);
    *result = mx_strtrim(*result);
}

