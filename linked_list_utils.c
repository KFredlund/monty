#include "monty.h"

/**
 * print_dlistint - prints every element within a node of a single linked list
 * @h: List node passed in
 * Return: Count of what was printed.
 */
size_t print_stack(const stack_t *h)
{

	int i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * push_stack - adds a node
 * @head: Main passed in
 * @n: number to coy
 * Return: Always new
 */
stack_t *push_stack(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *head;

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		current->prev = new;
	*head = new;
	if (*head == NULL)
		return (NULL);

	return (new);
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
