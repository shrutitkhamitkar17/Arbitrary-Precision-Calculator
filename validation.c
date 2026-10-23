#include "DLL.h"

//Function to check whether the given string is a valid number
static int is_valid_number(const char *str)
{
    // Check if the number starts with a negative sign
    if (*str == '-')
    {
        str++;  // skip one optional sign
    }

    // If string is empty after '-' sign, it is invalid
    if (*str == '\0')
    {
        return FAILURE;             
    }

    // Check each character of the string is digit or not
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
        {
            return FAILURE;
        }
        str++;
    }
    return SUCCESS;
}

// Function to validate command line arguments
int validate_CLA(int argc, char *argv[])
{
    // Check whether exactly 3 command line arguments are provided or not
    if(argc != 4)
    {
        printf("ERROR: Invalid number of arguments\n");
        printf("Usage: ./a.out <num1> <operator> <num2>\n");
        return FAILURE;
    }

    // Validate the first operand
    if (is_valid_number(argv[1]) == FAILURE)
    {
        printf("ERROR: %s is invalid operand\n", argv[1]);
        return FAILURE;
    }

    // Validate the second operand
    if (is_valid_number(argv[3]) == FAILURE)
    {
        printf("ERROR: %s is invalid operand\n", argv[3]);
        return FAILURE;
    }

    // Check whether the operator is one of the supported operator or not
    if(argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != 'X' && argv[2][0] != '/')
    {
        printf("ERROR:  %s is invalid operator\n", argv[2]);
        printf("choose operator from +, -, x, X, /\n");
        return FAILURE;
    }

    return SUCCESS;
}