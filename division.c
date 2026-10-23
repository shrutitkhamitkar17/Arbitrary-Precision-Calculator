#include "DLL.h"

// Function to perform division of two numbers
int division(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail)
{
    // Check if the divisor is zero, print an error and return failure.
    int is_zero = 1;
    for (Dlist *t = *op2_head; t != NULL; t = t->next)
    {
        if (t->data != 0)
        {
            is_zero = 0;
            break;
        }
    }
    if (is_zero)
    {
        printf("ERROR: Division by zero is not possible\n");
        return FAILURE;
    }

    // If the first operand is zero, the result is zero
    if((*op1_head == NULL) || (*op1_tail == NULL))
    {
        insert_first(res_head, res_tail, 0);
        return SUCCESS;
    }

    Dlist *temp = *op1_head; // Pointer to traverse the first operand

    Dlist *rem_head = NULL; // Initialize remainder head to NULL
    Dlist *rem_tail = NULL; // Initialize remainder tail to NULL

    while(temp != NULL)
    {
        // Add one digit from the first operand to the remainder
        insert_last(&rem_head, &rem_tail, temp->data);

        temp = temp->next; // Move to the next digit in the first operand

        // Remove leading zeros from reminder
        while(rem_head != NULL && rem_head->data == 0 && rem_head->next != NULL)
        {
            Dlist *del = rem_head;
            rem_head = rem_head->next;
            rem_head->prev = NULL;
            free(del);
        }

        if(compare_lists(&rem_head, &rem_tail, op2_head, op2_tail) < 0)
        {
            insert_last(res_head, res_tail, 0);
        }
        else
        {
            int count = 0;

            while(compare_lists(&rem_head, &rem_tail, op2_head, op2_tail) >= 0)
            {
                Dlist *sub_head = NULL;
                Dlist *sub_tail = NULL;

                subtraction(&rem_head, &rem_tail, op2_head, op2_tail, &sub_head, &sub_tail);

                // Delete old remainder 
                delete_list(&rem_head, &rem_tail);

                // New remainder = subtraction result
                rem_head = sub_head;
                rem_tail = sub_tail;

                count++;
            }

            //Add count to the end of the quotient(result)
            insert_last(res_head, res_tail, count);
        }
    }

    // Remove leading zeros from quotient
    while (*res_head != NULL && (*res_head)->data == 0 && (*res_head)->next != NULL)
    {
        Dlist *del = *res_head;

        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;

        free(del);
    }

    // Delete remainder list
    delete_list(&rem_head, &rem_tail);

    return SUCCESS;
}