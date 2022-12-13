#include "monty.h"


/**
 * pop - removes and returns the last item from our global stack
 * Return: the last item which was removed
 */
int pop(void)
{
	int last_item;

	if (gs_length == 0)
	{
		/*print to std err that there is nothing left to pop and return*/
		printf("stackmis empty");
	}

	last_item = global_stack[gs_length - 1];
	gs_length--;
	return (last_item);
}


/**
 * push - pushes an item on top of the stack
 * @item: item to be pushed to the stack
 * Return: the pushed item
 */
int push(int item)
{
	if (gs_length == STACK_SIZE)
	{
		/*stack is full. notify std error and return*/
		printf("stack is full");
	}

	global_stack[gs_length] = item;
	gs_length++;
	return (item);
}



/**
 * pall -  prints all the values on the stack,
 * starting from the top of the stack.
 */
void pall(void)
{
	int i;

	if (gs_length == 0)
		return;

	for (i = gs_length - 1; i >= 0; i--)
		print("%d\n", globasl_stack[i]);
}

/**
 * pint -  prints the value at the top of the stack
 */
void pint(void)
{
	if (gs_length == 0)
		return;

	printf("%d\n", global_stack[gs_length - 1]);
}

/**
 * swap - swaps the top two elements of the stack.
 */
void swap(void)
{
	int top;
	int bottom;

	if(gs_length < 2)
	{
		/*need at least 2 items to initiate swap*/
		return;
	}

	top = pop();
	bottom = pop();
	push(top);
	push(bottom);
}
