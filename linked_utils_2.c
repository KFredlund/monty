#include "monty.h"
#include <ctype.h>
int is_integer(char *str);
void op_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
		handle_error(5, line_number, "hiiiii");
	printf("%d\n", (*head)->n);
}

void check_push(char **tokens, unsigned int line)
{
	if (strcmp(tokens[1], "push") == 0)
	{
		if (is_integer(tokens[1]) == 0)
			n = atoi(tokens[1]);
		else
			handle_error(4, line, "hiiiii");
	}
}

int is_integer(char *str)
{
	int i = 0;
	
	while(str[i])
		if (isdigit(str[i]) == 0 && isdigit(str[i]) != '-')
			return (1);
		i++;
	return (0);
}
