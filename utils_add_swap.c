#include "monty.h"
/**
 * op_add - adds the data from the top two nodes, creates a new node
 * and replaces them
 * @head: List node passed in
 * @line_number: line number var
 * Return: Never
 */
void op_add(stack_t **head, unsigned int line_number)
{
	int i = 0;
	stack_t *current = *head;
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (!new)
		new = NULL;
	new->n = current->n + current->next->n;
	new->next = NULL;
	new->prev = NULL;
	temp->n = new->n;
	if (current)
	{
		new = current->next;
		new->n = temp->n;
		(*head)->next->prev = new;
	}
	*head = new;
}

