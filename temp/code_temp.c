/**
 * swap - swaps the top two elements of the stack.
 * @stack: double pointer tail of the stack to push the item
 * @line_number: the line number where this
 * command can be found in the source file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeallandexit(*stack, gv.file, *gv.line, EXIT_FAILURE);
	}

	temp = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	if ((*stack)->prev->prev)
		(*stack)->prev->prev->next = (*stack);
	(*stack)->prev->prev = (*stack);
	(*stack)->prev = (*stack)->prev->prev;
	(*stack)->next = temp;
	(*stack) = temp;

}
