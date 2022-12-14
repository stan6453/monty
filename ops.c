#include "monty.h"

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		/*stackoverflow*/
		exit(-99999);
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
