#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * my_getline - custom getline function
 * @command_ptr: address of commands buffer
 * @byte_size: size of buffer
 * @input: stream input, that is standard input
 * Return: returns number of bytes from command input
 */

ssize_t my_getline(char **command_ptr, size_t *byte_size, FILE *input)
{
	int line;
	size_t buffer_size = *byte_size;
	size_t i = 0;
	char *new_ptr;

	if (command_ptr == NULL || byte_size == NULL || input == NULL)
	{
		return (-1);
	}
	if (*command_ptr == NULL || *byte_size == 0)
	{
		buffer_size = PATH_SIZE;
		*command_ptr = (char *)malloc(buffer_size * sizeof(char));
		if (*command_ptr == NULL)
		{
			return (-1);
		}
	}
	for (; (line = fgetc(input)) != EOF;)
	{
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			new_ptr = (char *)realloc(*command_ptr, buffer_size * sizeof(char));

			if (new_ptr == NULL)
			{
				return (-1);
			}
			*command_ptr = new_ptr;
		}
		(*command_ptr)[i++] = line;
		if (line == '\n')
		{
			break;
		}
	}
	(*command_ptr)[i] = '\0';
	*byte_size = buffer_size;
	return ((ssize_t)i);
}
