#include "monty.h"
#include <fcntl.h>

int linecount = 0;

int main(int argc, char **argv)
{
	char *line = NULL;
	char **tokens = NULL;
	FILE * fp;
	ssize_t i = 0;
	size_t buffersize = 0;

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
		printf("%s\n", tokens[0]);	

	}
	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
