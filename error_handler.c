#include "monty.h"
/**
 * handle_error - Handles errors of monty program
 * @flag: Flag for specfic error
 * @line_number: Self explanatory, line the error is on
 * @name: Name of the file or opcode
 */


void handle_error(int flag, unsigned int line_number, char *name)
{
	switch(flag)
	{
		case 1: /* Malloc Fails */
			fprintf(stderr, "Error: malloc failed\n");
		case 2: /* Can't open file */
			fprintf(stderr, "Error: Can't open file %s\n", name);
		case 3: /* Invalid Instruction */
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, name);
		case 4: /* Push fails */
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
		case 5: /* Pint fails */
			fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		case 6: /* Pop fails */
			fprintf(stderr,"L%u: can't pop an empty stack\n", line_number);
		case 7: /* Swap Fails */
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		case 8: /* Add fails */
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		case 9: /* Sub fails */
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		case 10: /* Div fails too short */
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		case 11: /* Div fails, division by zero */
			fprintf(stderr, "L%u: division by zero\n", line_number);
		case 12: /*Multiply Fails */
			fprintf(stderr, "L%u: can't mul, stack too short", line_number);
		case 13: /* Mod fails too short */
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		case 14: /* Mod fails, by zero */
			fprintf(stderr, "L%u: division by zero\n", line_number);
	}
	free_list(&tok_get);
	free_stack(list);
	fclose(fp);
	exit(EXIT_FAILURE);	
}