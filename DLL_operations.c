#include "DLL.h"    

// Function to insert a new node at the end of the doubly linked list
int insert_last(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for a new node
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
    
    // Check if memory allocation was successful
    if(newNode == NULL)
    {
        printf("\nMemory allocation is failed");
        return FAILURE;
    }
    
    //Initialize newNode
    newNode->data = data;
    newNode->next = NULL;
    
    // Check if the list is empty or not
    if(*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
    }

    *tail = newNode;

    return SUCCESS;
}

int insert_first(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for the new node
    Dlist *newNode = (Dlist *)malloc(sizeof(Dlist));
    
    // Check if memory allocation was successful
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    
    // Initialize the new node
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    
    // Update the head and tail pointers
    if(*head == NULL)
    {
        *tail = newNode;
    }
    else
    {
        (*head)->prev = newNode;
    }
    
    // Update the head pointer to point to the new node
    *head = newNode;
    
    return SUCCESS;
}

// Function to delete all nodes from the doubly linked list
int delete_list(Dlist **head, Dlist **tail)
{
    // Check if the list is empty or not
    if(head == NULL || *head == NULL)
    {
        return FAILURE;
    }
    
    Dlist *temp = *head;
    
    // Traverse the entire list
    while(temp != NULL)
    {
        // Store address of current node brfore delete
        Dlist *next = temp->next;
        // Free the current node
        free(temp);
        // Move to the next node
        temp = next;
    }
    
    // Reset head and tail after deleting the complete list
    *head = NULL;
    *tail = NULL;
    
    return SUCCESS;
}

// Function to compare two doubly linked lists
/* Returns:
1 -> first list is greater 
-1 -> second list is greater 
0 -> both lists are equal */
int compare_lists(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail)
{
    // Variables to store the length of both lists
    int len1 = 0, len2 = 0;

    //Pointers to traverse 
    Dlist *temp1 = *op1_head;
    Dlist *temp2 = *op2_head;   

    // Calculate the length of the first list
    while(temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }           

    // Calculate the length of the second list
    while(temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Compare lengths
    if(len1 > len2)
    {
        return 1; // First list is greater
    }
    else if(len1 < len2)
    {
        return -1; // Second list is greater
    }
    else
    {
    // If lengths are equal, compare digit by digit

        // Reset pointers to the beginning of both lists
        temp1 = *op1_head;
        temp2 = *op2_head;

        // Traverse both lists simultaneously
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                return 1; // First list is greater
            }
            else if(temp1->data < temp2->data)
            {
                return -1; // Second list is greater
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return 0; // Both lists are equal
    }
}

// Function to print the number stored in the doubly linked list
void print_list(Dlist **head, int sign)
{
    // Check if the list is empty or not
    if (head == NULL || *head == NULL)
	{
		printf("INFO : List is empty\n");
        return;
	}
	
    printf("Result : "); 
        
    // Print the sign if it's negative
    if (sign == -1)
    {
        printf("-");
    }
        
    // Pointer for traverse
    Dlist *temp = *head;

    // Traverse the list and print each digit
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;   
    }
    
    printf("\n");
    
}

