#include "monty.h"
void handle_error_2(int flag, unsigned int l_n);
/**
 * handle_error - Handles errors of monty program
 * @flag: Flag for specfic error
 * @line_number: Self explanatory, line the error is on
 * @name: Name of the file or opcode
 * Return: None
 */


void handle_error(int flag, unsigned int line_number, char *name)
{
	switch (flag)
	{
		case 1: /* Malloc Fails */
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 2: /* Can't open file */
			fprintf(stderr, "Error: Can't open file %s\n", name);
			break;
		case 3: /* Invalid Instruction */
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, name);
			break;
		case 4: /* Push fails */
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			break;
		case 5: /* Pint fails */
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
			break;
		case 6: /* Pop fails */
			fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
			break;
		case 7: /* Swap Fails */
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			break;
		case 8: /* Add fails */
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			break;
		case 9: /* Sub fails */
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
			break;
		case 10: /* Div fails too short */
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
			break;
		default:
			handle_error_2(flag, line_number);
	}
	free_list(&tok_get);
	free_stack(list);
	free(tokens);
	if (flag != 2)
		fclose(fp);
	exit(EXIT_FAILURE);
}
/**
 * handle_error_2 - Handles errors of monty program
 * @flag: Flag for specfic error
 * @line_number: Self explanatory, line the error is on
 * Return: Never
 */
void handle_error_2(int flag, unsigned int line_number)
{
	switch (flag)
	{
		case 11: /* Div fails, division by zero */
			fprintf(stderr, "L%u: division by zero\n", line_number);
			break;
		case 12: /*Multiply Fails */
			fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
			break;
		case 13: /* Mod fails too short */
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
			break;
		case 14: /* Mod fails, by zero */
			fprintf(stderr, "L%u: division by zero\n", line_number);
			break;
		case 15: /* Can't pchar, value out of range */
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
			break;
		case 16: /* Pchar empty stack */
			fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
			break;
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
	}
	free_list(&tok_get);
	free_stack(list);
	free(tokens);
	if (flag != 0)
		fclose(fp);
	exit(EXIT_FAILURE);
}
