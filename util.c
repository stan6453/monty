#include "monty.h"


void freestack(stack_t *stacktail)
{
	stack_t *temp;

	if (stacktail == NULL)
		return;

	while(stacktail && stacktail->prev != NULL)
	{
		temp = stacktail->prev;
		free(stacktail);
		stacktail = temp;
	}

	free(stacktail);
}
