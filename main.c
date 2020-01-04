#include "monty.h"
#include <fcntl.h>

int n = 0;

int main(int argc, char **argv)
{
	char *line = NULL; 
	char **tokens = NULL;
	FILE * fp = NULL;
	ssize_t i = 0, c = 1;
	size_t buffersize = 1024; 
	void (*func)(stack_t **, unsigned int);
	unsigned int count = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	while (c == 1)
	{
		i = getline(&line, &buffersize, fp);
		add_node(line);
		if (i != -1)
		{
			printf("Got the line\n");
			printf("Before Parse: %s\n", line);
			tokens = parse_line(line);
			printf("After parse: %s\n", tokens[1]);
			if (tokens[1] != NULL)
				n = atoi(tokens[1]);
			func = getop(tokens[0]);
			printf("Reached\n");
			func(&list, count);
		}
		else
			c = 0;
		free(tokens);
		count++;
	}
	fclose(fp);
	free_list(&tok_get);
	free_stack(list);
	return (0);
}

void add_node(char *str)
{
	used_m *new;
	new = malloc(sizeof(used_m));
	if (new == NULL)
		exit(EXIT_FAILURE);

	new->data = str;
	new->next = tok_get;
	tok_get = new;
}

void free_list(used_m **head)
{
	used_m *new;
	used_m *current;

	if (*head)
	{
		current = *head;
		while (current)
		{
			new = current;
			current = current->next;
			free(new->data);
			free(new);
		}
	}
}
