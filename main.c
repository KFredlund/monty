#include "monty.h"
#include <fcntl.h>

int linecount = 0;

int main(int argc, char **argv)
{
	char *line = NULL;
	FILE * fp;
	ssize_t i = 0;
	size_t buffersize = 0;

	if (argc != 2)
		exit (EXIT_FAILURE);

	fp = fopen(argv[1], O_RDONLY);

	while (i != -1)
	{
		i = getline(&line, &buffersize, fp);
		printf("%s", line);
	}
	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
