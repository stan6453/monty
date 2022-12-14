#include "monty.h"

void printstack(stack_t *stacktail)
{
	while (stacktail)
	{
		printf("%d\n", stacktail->n);
		stacktail = stacktail->prev;
	}
}
