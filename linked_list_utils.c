#include "monty.h"

/**
 * print_dlistint - prints every element within a node of a single linked list
 * @h: List node passed in
 * Return: Count of what was printed.
 */
void op_pall(stack_t **head, unsigned int line_number)
{

	int i = 0;

	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
		i++;
	}
}

/**
 * push_stack - adds a node
 * @head: Main passed in
 * @n: number to coy
 * Return: Always new
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *stack;
	if (new == NULL)	
		exit(EXIT_FAILURE);

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		current->prev = new;
	*stack = new;
	if (*stack == NULL)
		exit(EXIT_FAILURE);
}
/**
 * pop_stack - Deletes top Node of stack
 * @headL stack
 * Return: -1 if fails
 */
int pop_stack(stack_t **head)
{
	stack_t *current;
	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	*head = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
	return (1);
}

/**
 * free_dlistint - Frees a singly linked list
 * @head: List to free
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *new;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new);
	}
	free(head);
}
