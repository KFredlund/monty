#include "monty.h"
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/**
 * parse_line - Uses strtok to put args in array
 *
 * @line: char pointer
 *
 * Return: Double char pointer
 */

char **parse_line(char *line)
{
	int buffer_size = BUFFERSIZE;
	int location = 0;
	char **tokens = NULL;
	char *token = NULL;

	tokens = malloc(sizeof(char *) * 3);
	if (!tokens)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIMINATOR);
	while (location < 2)
	{
		tokens[location] = token;
		token = strtok(NULL, DELIMINATOR);
		location++;
	}
	if (location >= buffer_size)
	{
		buffer_size += BUFFERSIZE;
		tokens = _realloc(tokens, BUFFERSIZE, buffer_size * sizeof(char *));

		if (!tokens)
		{
			{
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIMINATOR);
	}
	tokens[location] = NULL;
	return (tokens);
}
/**
 * _realloc - Reallocating space for a memory block
 * @ptr: Pointer passed in
 * @old_size: Old size of the array
 * @new_size: New size of the array
 * Return: Never
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_pointer;
	unsigned int i = 0;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_pointer = malloc(new_size);
	if (new_pointer == NULL)
		return (NULL);

	while (i < old_size)
	{
		*((char *)new_pointer + i) = *((char *)ptr + i);
		i++;
	}
	free(ptr);
	return (new_pointer);
}
