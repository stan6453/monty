#include "monty.h"




/**
 * printstack - prints all the items in the stack
 * @stacktail: pointer to the tail node of the stack
 */
void printstack(stack_t *stacktail)
{
	while (stacktail)
	{
		printf("%d\n", stacktail->n);
		stacktail = stacktail->prev;
	}
}
