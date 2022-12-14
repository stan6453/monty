#include "monty.h"


/**
 * main - program execution starts here
 * @argc: number of command line arguments passed to our program
 * @argv: vector containing list of all command line args
 * Return: 0 if program exited without errors
 */
int main(int argc __attribute__((unused)), char **argv)
{
	FILE *file = fopen(argv[1], "r");
	size_t linesize = 1;
	char *line = (char *) malloc(1);
	stack_t *stacktail = NULL;
	unsigned int line_number = 0;
	char *cmd[3];


	if (line == NULL)
	{
		/*print error and return*/
		fclose(file);
		return (1);
	}

	if (file == NULL)
	{
		/*file could not be opend retunr error appropriately*/
		free(line);
		return (1);
	}

	while (_getline(&line, &linesize, file))
	{
		line_number++;
		if (line[0] == '\0')
			continue;
		tokenize_string(line, cmd);
		execute_cmd(cmd, &stacktail, line_number);
	}

	
	if (line == NULL)
	{
		/*print error and return*/
		fclose(file);
		return (1);
	}

	if (file == NULL)
	{
		/*file could not be opend retunr error appropriately*/
		free(line);
		return (1);
	}

	while(_getline(&line, &linesize, file))
	{
		line_number++;
		tokenize_string(line,cmd);
		execute_cmd(cmd, &stacktail, line_number);
	}
		
	if (file)
		fclose(file);
	if (line)
		free(line);
	return (0);
}

/**
 * _getline - return the next available line from a file stream
 * @line: pointer to a pointer to a buffer
 * @linesize: pointer to int containing the size of the allocated buffer
 * @file: file pointer to get line from
 * Return: number of bytes read from file
 */
size_t _getline(char **line, size_t *linesize, FILE *file)
{
	size_t characters;

	characters = getline(line, linesize, file);

	if (feof(file))
	{
		fclose(file);
		free(*line);
		exit(1);
	}

	/*remove the newline at the end*/
	(*line)[characters - 1] = '\0';

	return (characters);
}

/**
 * tokenize_string - breaks a string into individual words
 * and points to those words while delimiting any space after the word
 * with the null character '\0'
 * @line: string to tokentize
 * @cmd: an array to store pointers to each word that was tokenized
 */
void tokenize_string(char *line, char *cmd[])
{
	int i = 0;

	cmd[i] = strtok(line, " ");
	while (cmd[i] != NULL)
	{
		i++;
		cmd[i] = strtok(NULL, " ");
	}
}

/**
 * execute_cmd - gets the command of a particular opcode and executes it.
 * @cmd: an array containing opcode at index 0
 * and the argument to that opcode at index 1
 * @stack: double pointer to the stack to operate on
 * @line_number: the line number where this command
 * can be found in the source file
 */
void execute_cmd(char *cmd[], stack_t **stack, unsigned int line_number)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = get_cmd(cmd[0]);

	f(stack, line_number);
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

void tokenize_string(char *line, char *cmd[])
{
	int i = 0;

	cmd[i] = strtok(line, " ");
	while (cmd[i] != NULL)
	{
		i++;
		cmd[i] = strtok(NULL, " ");
	}
}


void execute_cmd(char *cmd[], stack_t **stack, unsigned int line_number)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = get_command_to_execute(cmd[0]);

	f(stack, line_number);
}


void (*get_command_to_execute(char *op))(stack_t **stack, unsigned int line_number)
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
