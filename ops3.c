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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
	temp->n = bottom % top;
	(*stack) = temp;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	/*0 - 127 are the printable ascii characters*/
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	/*print char*/
	printf("%c\n", (*stack)->n);
}




/**
 * pstr - prints the string starting at the top of the stack, followed by a new line.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp = (*stack);

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	while(temp){

		/*0 - 127 are the printable ascii characters*/
		if ((temp->n < 65 || temp->n > 126) && temp->n != 32)
		{
			printf("\n");
			return;
		}
		printf("%c", temp->n);
		temp = temp->prev;
	}
	printf("\n");
}
