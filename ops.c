#include "monty.h"



/**
 * push - pushes an item on top of a stack
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = push_argument;
	newnode->next = NULL;
	newnode->prev = NULL;

	if ((*stack) == NULL)
		(*stack) = newnode;
	else
	{
		newnode->prev = (*stack);
		(*stack)->next = newnode;
		(*stack) = newnode;
	}
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if(*stack == NULL)
		return;

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
