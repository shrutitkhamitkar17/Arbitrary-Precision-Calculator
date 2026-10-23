#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

// Structure definition for a doubly linked list node
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

// Function to validate command line arguments
int validate_CLA(int argc, char *argv[]);

// Function to convert input number string into a doubly linked list
int slicing_input_dll(Dlist **head, Dlist **tail, char *input);

// Function to insert a node at the end of the doubly linked list
int insert_last(Dlist **head, Dlist **tail, int data);

// Function to insert a node at the beginning of the doubly linked list
int insert_first(Dlist **head, Dlist **tail, int data);

// Function to print the number stored in the doubly linked list
void print_list(Dlist **head, int sign);

// Function to delete all nodes from the doubly linked list
int delete_list(Dlist **head, Dlist **tail);

// Function to compare two numbers stored in doubly linked lists
int compare_lists(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail);

// Function to perform addition of two numbers
int addition(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail);

// Function to perform subtraction of two numbers
int subtraction(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail);

// Function to perform multiplication of two numbers
int multiplication(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail);

// Function to perform division of two numbers
int division(Dlist **op1_head, Dlist **op1_tail, Dlist **op2_head, Dlist **op2_tail, Dlist **res_head, Dlist **res_tail);

#endif