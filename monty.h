#ifndef MONTY_H
#define MONTY_H

#define DELIMINATOR "\n "
#define BUFFERSIZE 1024


typedef struct used_memory
{
	char *data;
	struct used_memory *next;
} used_m;

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
int n;

extern FILE * fp;
FILE * fp;

extern stack_t *list;
stack_t *list;

extern used_m *tok_get;
used_m *tok_get;

extern char **tokens;
char **tokens;

void op_pall(stack_t **stack, unsigned int l_number);
void op_push(stack_t **stack, unsigned int l_number);
void op_pop(stack_t **head, unsigned int l_number);
void op_add(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_swap(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_pstr(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);
char **parse_line(char *line);
void (*getop(char *s, unsigned int count))(stack_t **stack, unsigned int line_number);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void add_node(char *str);
void free_list(used_m **head);
void op_pchar(stack_t **head, unsigned int l_number);
void handle_error(int flag, unsigned int line_number, char *name);
void check_push(char **tokens, unsigned int line);
#endif
