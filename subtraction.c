#include "DLL.h"

// Function to perform subtraction of two numbers
int subtraction(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail)
{
    // Variable to store borrow from the previous digit
    int borrow = 0;

    Dlist *temp1 = *op1_tail;
    Dlist *temp2 = *op2_tail;

    // Initialize the result list as empty
    *res_head = NULL;
    *res_tail = NULL;

    // Traverse list of op1 from the tail to the head
    while(temp1 != NULL)
    {
        // Variable to store the current digit of operand 2
        int digit;

        if(temp2 != NULL)
        {
            digit = temp2->data;
        }
        else{
            digit = 0;
        }

        // Subtract the digits along with any previous borrow
        int diff = temp1->data - digit - borrow;

        // If the result is negative, borrow 10 from the next digit
        if(diff < 0)
        {
            diff = diff + 10;   //borrow 10 from the next digit
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        //Insert calculated digit at beginning of result
        insert_first(res_head, res_tail, diff);

        //Move operand 1 pointer to previous digit 
        temp1 = temp1->prev;

        // If operand 2 digit available move it to previous digit
        if(temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }

    // Remove leading zeros
    while(*res_head != NULL && (*res_head)->data == 0 && (*res_head)->next != NULL)
    {
        Dlist *del = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(del);
    }
    
    return SUCCESS;
}