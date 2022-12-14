#include "monty.h"


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
	return(0);
}


size_t _getline(char **line, size_t *linesize, FILE *file)
{
	size_t characters;

	characters = getline(line, linesize, file);

	if (feof(file))
	{
		printf("\nend of file\n");
		fclose(file);
		free(*line);
		exit(1);
	}
	
	return (characters);	
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
