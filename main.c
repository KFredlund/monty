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
	unsigned int count = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	while (i != -1)
	{
		i = getline(&line, &buffersize, fp);
		printf("Got the line\n");
		printf("Before Parse: %s\n", line);
		tokens = parse_line(line);
		printf("After parse: %s\n", tokens[1]);
		if (tokens[1] != NULL)
			n = atoi(tokens[1]);
		func = getop(tokens[0]);
		printf("Reached\n");
		func(&list, count);
		free(tokens);
		free(line);
		count++;
	}
	fclose(fp);
	return (0);
}
