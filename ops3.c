#include "monty.h"

/**
 * mod -  computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int top, bottom;
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	top = (*stack)->n;
	bottom = (*stack)->prev->n;

	temp = (*stack)->prev;
	free(*stack);
	temp->n = bottom % top;
	(*stack) = temp;
}
