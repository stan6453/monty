#include "monty.h"

/**
 * freestack - deletes the stack deallocate memory assinged to it
 * @stacktail: pointer to the tail node of the stack
 * Return: 0 if program exited without error
 */
void freestack(stack_t *stacktail)
{
	stack_t *temp;

	if (stacktail == NULL)
		return;

	while (stacktail && stacktail->prev != NULL)
	{
		temp = stacktail->prev;
		free(stacktail);
		stacktail = temp;
	}

	free(stacktail);
}



/**
 * freeallandexit - free all resources this
 * program is using and exit with exit.
 * @stacktail: stack to deallocate
 * @file: open file poiner to close
 * @line: this is the variable the program uses
 * to read each line of the opcode file
 * @exitcode: the exit code you want your program to exit with
 */
void freeallandexit(stack_t *stacktail, FILE *file, char *line, int exitcode)
{
	freestack(stacktail);

	if (line)
		free(line);
	if (file)
		fclose(file);
	exit(exitcode);

}
