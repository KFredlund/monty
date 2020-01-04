#include "monty.h"


void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	if (*head == NULL || head == NULL)
	{
		exit(EXIT_FAILURE);
	}
	current = *head;
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}


void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	if (*head == NULL || head == NULL)
	{
		exit(EXIT_FAILURE);
	}
	current = *head;

	while (current->next)
	{
		if (current->n > 127 || current->n < 32)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	putchar('\n');
}
