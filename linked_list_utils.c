#include "monty.h"

/**
 * print_dlistint - prints every element within a node of a single linked list
 * @h: List node passed in
 * Return: Count of what was printed.
 */
void op_pall(stack_t **head, unsigned int line_number)
{

	int i = 0;
	stack_t *current = list;
	printf("Entered pall\n");
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		i++;
	}
	printf("Left Pall\n");
}

/**
 * push_stack - adds a node
 * @head: Main passed in
 * @n: number to coy
 * Return: Always new
 */
void op_push(stack_t **list_add, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *list_add;
	if (new == NULL)	
		exit(EXIT_FAILURE);

	new->n = n;
	new->prev = NULL;
	new->next = current;
	if (*list_add != NULL)
		current->prev = new;
	*list_add = new;
	printf("Reached in func\n");
	printf("%d\n", list->n);
	printf("After func\n");
}
/**
 * op_pop - Pop the top element of the stack
 * @head: Head of linked list
 * @line_number: Self explanatory
 * Return: Never
 */
void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	if (head == NULL || *head == NULL)
		exit(EXIT_FAILURE);

	current = *head;
	*head = current->next;
	if (current->next != NULL)
		current->next->prev = NULL;
	free(current);
}
/**
 * op_nop - prints every element within a node of a single linked list
 * @h: List node passed in
 * Return: Count of what was printed.
 */
void op_nop(stack_t **head, unsigned int line_number)
{
	int i = 1;

	while (i >= 0)
	{
		i--;
		continue;
	}
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
