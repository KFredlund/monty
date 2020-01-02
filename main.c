#include "monty.h"
#include <fcntl.h>

int n = 0;

int main(int argc, char **argv)
{
	char *line = NULL; 
	char **tokens = NULL;
	FILE * fp;
	ssize_t i = 0;
	size_t buffersize = 0;
	void (*func)(stack_t **, unsigned int);
	int count = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file");
		exit (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	while (i != -1)
	{
		i = getline(&line, &buffersize, fp);
		tokens = parse_line(line);
		if (tokens[1])
			n = atoi(tokens[1]);
		func = getop(*tokens);
		printf("Reached");
		func(&stack, count);

		free(line);
		count++;
	}
	fclose(fp);
	return (0);
}
