#include "monty.h"

/**
 * add - swaps the top two elements of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void add(stack_t **stack, unsigned int line_number)
{
	int top, bottom;
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	top = (*stack)->n;
	bottom = (*stack)->prev->n;

	temp = (*stack)->prev;
	free(*stack);
	temp->n = top + bottom;
	(*stack) = temp;
}


/**
 * nop - doesn’t do anything.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}



/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int top, bottom;
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	top = (*stack)->n;
	bottom = (*stack)->prev->n;

	temp = (*stack)->prev;
	free(*stack);
	temp->n = bottom - top;
	(*stack) = temp;
}


/**
 * div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void idiv(stack_t **stack, unsigned int line_number)
{
	int top, bottom;
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	top = (*stack)->n;
	if (top == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}
	bottom = (*stack)->prev->n;

	temp = (*stack)->prev;
	free(*stack);
	temp->n = bottom / top;
	(*stack) = temp;
}

