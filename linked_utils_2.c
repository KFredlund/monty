#include "monty.h"

void op_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
		exit(EXIT_FAILURE);
	printf("%d\n", (*head)->n);
}
