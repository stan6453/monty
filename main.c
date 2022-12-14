#include "monty.h"


int main(int argc, char **argv)
{
	char *line = (char *) malloc(1);
	size_t linesize = 1;
	FILE *file = fopen(argv[1], "r");

	printf("type something\n");
	while(_getline(&line, &linesize, file))
		printf("%s", line);
		

	return(0);
}


size_t _getline(char **line, size_t *linesize, FILE *file)
{
	size_t characters;

	characters = getline(line, linesize, file);

	if (feof(file))
	{
		printf("end of file\n");
		fclose(file);
		free(*line);
		exit(1);
	}
	
	return (characters);	
}
