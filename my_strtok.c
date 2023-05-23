#include <stdio.h>
#include "main.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

static int tokenize(char **buffer, const char *delimiters, char *tokens[]);
/**
 * tokenize - helper function to tokenize the input string
 * @buffer: pointer to the input string
 * @delimiters: delimiters such as space
 * @tokens: split commands stored in an array
 * Return: number of tokens, i.e., number of commands
 */
static int tokenize(char **buffer, const char *delimiters, char *tokens[])
{
	int num_tokens = 0;
	const char *delim;
	bool isDelimiter;

	while (**buffer != '\0' && num_tokens < MAX_COMMANDS)
	{
		isDelimiter = false;
		for (delim = delimiters; *delim != '\0'; delim++)
		{
			if (**buffer == *delim)
			{
				isDelimiter = true;
				break; }
		}
		if (isDelimiter)
		{
			**buffer = '\0';
			(*buffer)++; }
		else
		{
			tokens[num_tokens] = *buffer;
			num_tokens++;
			while (**buffer != '\0' && !isDelimiter)
			{
				for (delim = delimiters; *delim != '\0'; delim++)
				{
					if (**buffer == *delim)
					{
						isDelimiter = true;
						break; }
				}
				if (!isDelimiter)
					(*buffer)++;
			}
		}
	}
	tokens[num_tokens] = NULL;
	return (num_tokens);
}

/**
 * my_strtok - function mimicking strtok function
 * @command_ptr: pointer to commands from input
 * @delimiters: delimiters such as space
 * @tokens: split commands stored in an array
 * Return: number of tokens, i.e., number of commands
 */
int my_strtok(char *command_ptr, const char *delimiters, char *tokens[])
{
	static char *buffer;

	if (command_ptr != NULL)
		buffer = command_ptr;
	if (buffer == NULL || *buffer == '\0')
		return (0);

	return (tokenize(&buffer, delimiters, tokens));
}

