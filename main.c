#include "monty.h"
#include <fcntl.h>
#include <ctype.h>
/**
* main - Entry point
* @argc: number of args
* @argv: pointer to args
*
* Return: Never
*/
int main(int argc, char **argv)
{
	char *line = NULL;
	ssize_t i = 0, c = 1;
	size_t buffersize = 0;
	void (*func)(stack_t **, unsigned int);
	unsigned int count = 1;

	if (argc != 2)
		handle_error(0, count, argv[1]);
	fp = fopen(argv[1], "r");
	if (!fp)
		handle_error(2, count, argv[1]);
	tokens = NULL;
	while (c == 1)
	{
		line = NULL;
		i = getline(&line, &buffersize, fp);
		add_node(line);
		if (line[0] == '#')
		{
			count++;
			continue;
		}
		if (i != -1)
		{
			tokens = parse_line(line);
			func = getop(tokens[0], count);
			if (tokens[1] != NULL)
				check_push(tokens, count);
			func(&list, count), free(tokens);
		}
		else
			c = 0;
		count++;
	}
	fclose(fp);
	free_list(&tok_get), free_stack(list);
	return (0);
}
/**
* add_node - Function that adds a node
* @str: top of stack
*
* Return: Never
*/
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
/**
* free_list - Function that frees a list
* @head: top of stack
*
* Return: Never
*/
void free_list(used_m **head)
{
	used_m *new;
	unsigned int i = 0;

	if (*head)
	{
		while (*head)
		{
			new = *head;
			*head = (*head)->next;
			if (new->data != NULL)
				free(new->data);
			free(new);
			i++;
		}
	}
}
