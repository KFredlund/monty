#ifndef MONTY_H
#define MONTY_H

#define DELIMINATOR "\n "
#define BUFFERSIZE 1024
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern int n;

extern stack_t *list;
stack_t *list;

void op_pall(stack_t **stack, unsigned int l_number);
void op_push(stack_t **stack, unsigned int l_number);
int pop_stack(stack_t **head);
void free_stack(stack_t *head);
char **parse_line(char *line);
void (*getop(char *s))(stack_t **stack, unsigned int line_number);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
