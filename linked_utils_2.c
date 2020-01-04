#include "monty.h"

void op_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
		handle_error(5, line_number, "hiiiii");
	printf("%d\n", (*head)->n);
}
