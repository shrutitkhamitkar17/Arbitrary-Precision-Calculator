#include "DLL.h"

// Function to add two numbers stored in doubly linked lists
int addition(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail)
{
    // Check whether any of the required pointers are NULL
    if (res_head == NULL || res_tail == NULL ||
        op1_head == NULL || op1_tail == NULL ||
        op2_head == NULL || op2_tail == NULL)
    {
        return FAILURE;
    }
    // Initialize the result list as empty
    *res_head = NULL;
    *res_tail = NULL;

    // Variable to store carry
    int carry = 0;

    // Pointer for traversing
    Dlist *temp1 = *op1_tail;
    Dlist *temp2 = *op2_tail;

    // Continue traverse until both lists traverse and there is no remaining carry
    while (temp1 != NULL || temp2 != NULL || carry !=0)
    {
        // Start the sum with the previous carry 
        int sum = carry;

        // If operand 1 has a digit, add it to sum
        if(temp1 != NULL)
        {
            sum += temp1->data;
            temp1 = temp1->prev;
        }
        // If operand 2 has a digit, add it to sum
        if(temp2 != NULL)
        {
            sum += temp2->data;
            temp2 = temp2->prev;
        }

        // Add last digit of sum at begining of result 
        insert_first(res_head, res_tail, sum % 10);

        // Calculate carry for the next digit
        carry = sum / 10;
    }

    return SUCCESS;
}