#include "DLL.h"

// Function to perform multiplication of two numbers
int multiplication(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail)
{
    // If any of the operands is zero, then result is zero
    if((*op1_head == NULL) || (*op2_head == NULL))
    {
        insert_first(res_head, res_tail, 0);
        return SUCCESS;
    }

    int shift = 0; // To keep track of the position for each digit multiplication

    if(compare_lists(op1_head, op1_tail, op2_head, op2_tail) < 0)
    {
        // If the first operand is smaller than the second, swap them
        Dlist *temp_head = *op1_head;
        Dlist *temp_tail = *op1_tail;
        *op1_head = *op2_head;
        *op1_tail = *op2_tail;
        *op2_head = temp_head;
        *op2_tail = temp_tail;
    }
    
    *res_head = NULL;
    *res_tail = NULL;

    Dlist *temp2 = *op2_tail;

    while(temp2 != NULL)
    {
        int carry = 0;
        Dlist *temp1 = *op1_tail;

        // Create a temporary result list for the current digit multiplication
        Dlist *temp_res_head = NULL;
        Dlist *temp_res_tail = NULL;

        // Add zeros for the current shift
        for(int i = 0; i < shift; i++)
        {
            insert_last(&temp_res_head, &temp_res_tail, 0);
        }

        while(temp1 != NULL)
        {
            int product = temp1->data * temp2->data + carry;
            insert_first(&temp_res_head, &temp_res_tail, product % 10);
            carry = product / 10;
            temp1 = temp1->prev;
        }

        if(carry > 0)
        {
            insert_first(&temp_res_head, &temp_res_tail, carry);
        }

        // Add the temporary result to the final result
        Dlist *sum_head = NULL;
        Dlist *sum_tail = NULL;
        addition(res_head, res_tail, &temp_res_head, &temp_res_tail, &sum_head, &sum_tail);
        
        // Free the old running total and the partial product
        delete_list(res_head, res_tail);
        delete_list(&temp_res_head, &temp_res_tail);

        //The new sum become the running total
        *res_head = sum_head;
        *res_tail = sum_tail;

        temp2 = temp2->prev;
        shift++;
    }

    // Remove leading zeros
    while (*res_head != NULL && (*res_head)->data == 0 && (*res_head)->next != NULL)
    {
        Dlist *del = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(del);
    }

    return SUCCESS;
}