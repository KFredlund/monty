#include "monty.h"
/**
* op_mod - function that computes the rest of the division
* of the second top element of the stack by the
* top element of the stack
* @head: top of stack
* @line_number: line number passed here
*
*Return: Never
*/
void op_mod(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int i = 0;

	if (*head && (*head)->next)
	{
		if ((*head)->n == 0)
			handle_error(14, line_number, "hiiiii");
		current = *head;
		i = current->next->n % current->n;
		current->next->n = i;
		current->next->prev = NULL;
		*head = (*head)->next;
		free(current);
	}
	else
		handle_error(13, line_number, "hiiiii");
}
