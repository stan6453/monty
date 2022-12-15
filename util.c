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


/**
 * isonlydigit - checks if a string contains only digits
 * @s: string to be checked
 * Description: checks if a string contains only digit
 * Return: 1 if string contains only didgit
 *         0 if string has at lest one non-digit character
 */
int isonlydigit(char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}



/**
 * first_char_is_digit - checks if a string
 * contains a digits as the first character
 * @s: string to be checked
 * Return: 1 if string contains only didgit
 *         0 if string has at lest one non-digit character
 */
int first_char_is_digit(char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '\0')
		return (0);
	return (s[0]  >= '0' && s[0] <= '9');
}
