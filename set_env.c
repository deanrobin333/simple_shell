#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * my_setenv - Implementation of the setenv built-in command
 * Initializes a new environment variable or modifies an existing one
 * @variable: pointer to variable
 * @value: pointer to variable value
 * Command syntax: setenv VARIABLE VALUE
 * Return: 0
 */
int my_setenv(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
		return (-1);
	}
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "setenv: Failed to set environment variable\n");
		return (-1);
	}
	return (0);
}

/**
 * my_unsetenv - Implementation of the unsetenv built-in command
 * Removes an environment variable
 * @variable: variable being unset
 * Command syntax: unsetenv VARIABLE
 * Return: 0;
 */
int my_unsetenv(const char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
		return (-1);
	}
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
		return (-1);
	}
	return (0);
}

