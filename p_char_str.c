#include "monty.h"
/**
* op_pchar - Function that converts char on top of stack to letter
* @head: top of stack
* @line_number: line number
*
* Return: Never
*/
void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head == NULL || head == NULL)
		handle_error(16, line_number, "hiiii");

	current = *head;
	if (current->n > 127 || current->n < 0)
		handle_error(15, line_number, "hiiii");
	printf("%c\n", current->n);
}
/**
* op_pstr - Function that converts stack to ascii char
* @head: top of stack
* @line_number: line number
*
* Return: Never
*/
void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

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
