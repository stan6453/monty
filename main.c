#include "monty.h"

global_v gv = {NULL, NULL, INT_MIN};

/**
 * main - program execution starts here
 * @argc: number of command line arguments passed to our program
 * @argv: vector containing list of all command line args
 * Return: 0 if program exited without errors
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	run_program(argv);
	return (EXIT_SUCCESS);
}

/**
 * run_program - this is the program body. main execution starts here
 * @argv: argument vector containing all
 * command line arguments passed to program
 */
void run_program(char **argv)
{
	FILE *file = fopen(argv[1], "r");
	size_t linesize = 1;
	char *line = (char *) malloc(1);
	stack_t *stacktail = NULL;
	unsigned int line_number = 0;
	char *cmd[3];

	gv.file = file;
	gv.line = &line;
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(line);
		exit(EXIT_FAILURE);
	}
	while (_getline(&line, &linesize, file, stacktail))
	{
		line_number++;
		if (line[0] == '\0')
			continue;
		tokenize_string(line, cmd);
		if (execute_cmd(cmd, &stacktail, line_number) == -1)
			freeallandexit(stacktail, file, line, EXIT_FAILURE);
	}

	freeallandexit(stacktail, file, line, EXIT_SUCCESS);
}
/**
 * _getline - return the next available line from a file stream
 * @line: pointer to a pointer to a buffer
 * @linesize: pointer to int containing the size of the allocated buffer
 * @file: file pointer to get line from
 * @stacktail: used to free that stack when the program exits
 * Return: number of bytes read from file
 */
size_t _getline(char **line, size_t *linesize, FILE *file, stack_t *stacktail)
{
	size_t characters;

	characters = getline(line, linesize, file);

	if (feof(file))
	{
		fclose(file);
		free(*line);
		freestack(stacktail);
		exit(EXIT_SUCCESS);
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

	cmd[i] = strtok(line, " \t");
	while (cmd[i] != NULL)
	{
		i++;
		cmd[i] = strtok(NULL, " \t");
	}
}
