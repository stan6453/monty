#include "monty.h"


/**
 * execute_cmd - gets the command of a particular opcode and executes it.
 * @cmd: an array containing opcode at index 0
 * and the argument to that opcode at index 1
 * @stack: double pointer to the stack to operate on
 * @line_number: the line number where this command
 * can be found in the source file
 * Return: -1 on error 0 on success
 */
int execute_cmd(char *cmd[], stack_t **stack, unsigned int line_number)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	if (cmd[1] != NULL)
		push_argument = atoi(cmd[1]);

	f = get_cmd(cmd[0]);
	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd[0]);
		return (-1);

	}
	f(stack, line_number);

	return (0);
}

/**
 * get_cmd - returns a funtion to the caller
 * based on the opcode passed to it
 * @op: opcode to return the function for
 * Return: the function bound to the opcode that was received
 */
void (*get_cmd(char *op))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, op) == 0)
		{
			return (instructions[i].f);
		}
	}
	return (NULL);
}