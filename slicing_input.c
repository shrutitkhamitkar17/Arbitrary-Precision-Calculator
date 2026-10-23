#include "DLL.h"

// Function to convert the input number string into a doubly linked list
int slicing_input_dll(Dlist **head, Dlist **tail, char *input)
{
    int i = 0;

    //Skip leading zeros
    while(input[i] == '0' && input[i + 1] != '\0')
    {
        i++;
    }

    // Traverse the input string
    for(; input[i] != '\0'; i++)
    {
        // Convert the ASCII character digit into its integer value
        // Insert the digit at the end of the doubly linked list
        if(insert_last(head, tail, input[i] - '0') ==   FAILURE)
        {
            return FAILURE;
        }    
    } 
    
    return SUCCESS;
}