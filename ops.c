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
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	newnode->n = gv.push_argument;
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





/**
 * pall - prints all the items on the stack
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = *stack;

	if (*stack != NULL)
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
}

/**
 * pint - prints the value at the top of the
 * stack, followed by a new line.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}



/**
 * pop -  removes the top element of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	free(*stack);
	(*stack) = temp;
}



/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int top, bottom;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	top = (*stack)->n;
	bottom = (*stack)->prev->n;

	(*stack)->n = bottom;
	(*stack)->prev->n = top;
}
