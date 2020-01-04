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
	stack_t *current = *head;
	int i = 0;

	if ((*head)->next->next)
	{
		i = current->n + current->next->n;
		current->next->n = i;
		free(current);
		*head = (*head)->next;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * op_swap - swaps the top two nodes
 * @head: List node passed in
 * @line_number: line number var
 * Return: Never
 */
void op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	stack_t *hold = NULL;

	if (current)
	{
		hold = (*head)->next;
		current->next = hold->next;
		current->prev = hold;
		hold->prev = NULL;
		hold->next->prev = current;
		hold->next = current;
	}
	*head = hold;
}
/**
 * op_sub - subracts the data of the top node from the second,
 * and creates a new node and replaces them
 * @head: List node passed in
 * @line_number: line number var
 * Return: Never
 */
void op_sub(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int i = 0;

	if ((*head)->next->next)
	{
		i = current->n - current->next->n;
		current->next->n = i;
		free(current);
		*head = (*head)->next;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * op_div - divides the data of the top node from the second,
 * and creates a new node and replaces them
 * @head: List node passed in
 * @line_number: line number var
 * Return: Never
 */
void op_div(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int i = 0;

	if ((*head)->next->next)
	{
		i = current->n / current->next->n;
		current->next->n = i;
		free(current);
		*head = (*head)->next;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

}
/**
 * op_mul - multiplies the data of the top node from the second,
 * and creates a new node and replaces them
 * @head: List node passed in
 * @line_number: line number var
 * Return: Never
 */
void op_mul(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int i = 0;

	if ((*head)->next->next)
	{
		i = current->n * current->next->n;
		current->next->n = i;
		free(current);
		*head = (*head)->next;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

}
