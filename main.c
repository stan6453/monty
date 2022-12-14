#include "monty.h"

int push_argument = INT_MIN;

/**
 * main - program execution starts here
 * @argc: number of command line arguments passed to our program
 * @argv: vector containing list of all command line args
 * Return: 0 if program exited without errors
 */
int main(int argc __attribute__((unused)), char **argv)
{
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	run_program(argv);
	return (0);
}


void run_program(char **argv)
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
		exit (1);
	}

	if (file == NULL)
	{
		/*file could not be opend retunr error appropriately*/
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(line);
		exit (1);
	}

	while (_getline(&line, &linesize, file, stacktail))
	{
		line_number++;
		if (line[0] == '\0')
			continue;
		tokenize_string(line, cmd);
		execute_cmd(cmd, &stacktail, line_number);
	}


	if (file)
		fclose(file);
	if (line)
		free(line);
	/*if u run into any problem, fry freeing stacktail here*/
	exit (0);

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
		printstack(stacktail);
		freestack(stacktail);
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
