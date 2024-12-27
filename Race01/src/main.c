#include "../inc/part_of_the_matrix.h"

int main(int argc, char **argv) 
{

    if(argc != 5) 
    {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
        exit(EXIT_FAILURE);
    }

    char *operand1 = argv[1];
    char *operation = argv[2];
    char *operand2 = argv[3];
    char *result = argv[4];

    mx_parse_arguments(&operand1, &operation, &operand2, &result);
    mx_print_equation(operand1, operation, operand2, result);

    return 0;
}

