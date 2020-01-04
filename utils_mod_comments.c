#include "monty.h"
/*
*op_mod - function that computes the rest of the division
*of the second top element of the stack by the
*top element of the stack
*@head: top of stack
*@line_number: line number passed here
*
*Return: Never
*/
void op_mod(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next->next)
	{
		current->next->n = current->next->n % current->n;
		*head = current->next;
		free(current);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
