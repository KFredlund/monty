#include "monty.h"
#include <ctype.h>
int is_integer(char *str);
/**
 * op_pint - Prints head of list
 * @head: Head of the list
 * @line_number: line number
 * Return: Never
 */
void op_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
		handle_error(5, line_number, "hiiiii");
	printf("%d\n", (*head)->n);
}
/**
 * check_push - Check if the input is push
 * @tokens: The user input tokenized
 * @line: The line number
 * Return: Never
 */
void check_push(char **tokens, unsigned int line)
{
	if (strcmp(tokens[0], "push") == 0)
	{
		if (is_integer(tokens[1]) == 0)
			n = atoi(tokens[1]);
		else
			handle_error(4, line, "hiiiii");
	}
}
/**
 * is_integer - Checks if the input is an integer
 * @str: input to check
 * Return: 1 or 0
 */
int is_integer(char *str)
{
	unsigned long i = 0;

	while (i < strlen(str))
	{
		if (isdigit(str[i]) == 0 && str[0] != '-')
			return (1);
		i++;
	}
	return (0);
}
