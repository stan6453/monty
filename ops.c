#include "monty.h"


int push_argument = -9999999;
void push(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	printf("%d\n", push_argument);
}
