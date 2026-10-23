/*
Algorithm Steps : 
1. Start.
2. Call validate_CLA(). If it fails, print the error and stop.
3. Read op1 = argv[1], operator = argv[2][0], op2 = argv[3].
4. Set op1_sign = op2_sign = 1. If an operand starts with -, set its sign to -1 and skip that character.
5. Convert each operand string into a doubly linked list of digits with slicing_input_dll(). Skip leading zeros, and convert each character with ch - '0'.
6. Create an empty result list (res_head = res_tail = NULL).
7. Choose the operation from the operator:
        +: go to the addition algorithm
        -: go to the subtraction algorithm
        x or X: go to the multiplication algorithm
        /: go to the division algorithm
        anything else: print "Invalid Input"
8. Print the result with print_list(), adding - if res_sign is -1 (never for a result of 0).
9. Free the operand and result lists with delete_list().
10. Stop.
*/

#include "DLL.h"

int main(int argc, char *argv[])
{
    if(validate_CLA(argc, argv) == FAILURE)
    {
        printf("ERROR: Invalid command line arguments\n");
        return FAILURE;
    }

    int op1_sign = 1, op2_sign = 1, res_sign = 1; // 1 for positive, -1 for negative
    char *op1 = argv[1], *op2 = argv[3];

    if(op1[0] == '-')
    {
        op1_sign = -1;
        op1++; // Move pointer to skip the sign
    }

    if(op2[0] == '-')
    {
        op2_sign = -1;
        op2++; // Move pointer to skip the sign
    }

    Dlist *op1_head = NULL; //initialize the header to NULL
	Dlist *op1_tail = NULL; //initialize the tail to NULL

    if(slicing_input_dll(&op1_head, &op1_tail, op1) == FAILURE)
    {
        printf("ERROR: Failed to create list for operand 1\n");
        return FAILURE;
    }

    Dlist *op2_head = NULL; //initialize the header to NULL
	Dlist *op2_tail = NULL; //initialize the tail to NULL

    if(slicing_input_dll(&op2_head, &op2_tail, op2) == FAILURE)
    {
        printf("ERROR: Failed to create list for operand 2\n");
        return FAILURE;
    }

    Dlist *res_head = NULL; //initialize the header to NULL
	Dlist *res_tail = NULL; //initialize the tail to NULL

    char operator = argv[2][0];

    switch(operator)
    {
        case '+':
            if(op1_sign == op2_sign)
            {
                addition(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail);
                if(op1_sign == -1)
                {
                    res_sign = -1; // Result is negative if both operands are negative
                }
                print_list(&res_head, res_sign);
            }
            else
            {
                int cmp = compare_lists(&op1_head, &op1_tail, &op2_head, &op2_tail);
                if(cmp == 0)
                {
                    insert_first(&res_head, &res_tail, 0); // Result is zero
                    print_list(&res_head, 1);
                }
                else if(cmp > 0)
                {
                    subtraction(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail);
                    res_sign = op1_sign; // Result sign is the same as the first operand
                    print_list(&res_head, res_sign);
                }
                else
                {
                    subtraction(&op2_head, &op2_tail, &op1_head, &op1_tail, &res_head, &res_tail);
                    res_sign = op2_sign; // Result sign is the same as the second operand
                    print_list(&res_head, res_sign);
                }
            }
            break;

        case '-':
            if(op1_sign == op2_sign)
            {
                int cmp = compare_lists(&op1_head, &op1_tail, &op2_head, &op2_tail);
                if(cmp == 0)
                {
                    insert_first(&res_head, &res_tail, 0); // Result is zero
                    print_list(&res_head, 1);
                }
                else if(cmp > 0)
                {
                    subtraction(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail);
                    res_sign = op1_sign; // Result sign is the same as the first operand
                    print_list(&res_head, res_sign);
                }
                else
                {
                    subtraction(&op2_head, &op2_tail, &op1_head, &op1_tail, &res_head, &res_tail);
                    res_sign = -op1_sign; // Result sign is opposite of the first operand
                    print_list(&res_head, res_sign);
                }
            }
            else
            {
                addition(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail);
                res_sign = op1_sign; // Result sign is the same as the first operand
                print_list(&res_head, res_sign);
            }
            break;

        case 'x':
        case 'X':
            if(op1_sign == op2_sign)
            {
                multiplication(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail);
                res_sign = 1; // Result is positive if both operands have the same sign
                print_list(&res_head, res_sign);
            }
            else
            {
                multiplication(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail);
                res_sign = -1; // Result is negative if operands have different signs
                print_list(&res_head, res_sign);
            }
            break;

        case '/':
            if (division(&op1_head, &op1_tail, &op2_head, &op2_tail, &res_head, &res_tail) == FAILURE)
            {
                break;   // error already printed inside division(), skip printing the result
            }
            if (op1_sign == op2_sign)
            {
                res_sign = 1;    // same signs -> positive
            }
            else
            {
                res_sign = -1;   // different signs -> negative
            }

            print_list(&res_head, res_sign);
            break;
        default:
            printf("Invalid Input\n");
    }

    
    delete_list(&op1_head, &op1_tail);
    delete_list(&op2_head, &op2_tail);
    delete_list(&res_head, &res_tail);
    return 0;
}