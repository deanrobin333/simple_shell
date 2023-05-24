#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * builtin_commands - processes built in commands
 * @command: pointer to commands
 * @args: arguments
 * Return: void
 */

void builtin_commands(char *command, char *args[])
{
	if (strcmp("exit", command) == 0)
	{
		if (args[0] != NULL)
			my_exit(args[0]);
		else
			my_exit(NULL);
	}
	else if (strcmp("setenv", command) == 0)
		my_setenv(args[0], args[1]);
	else if (strcmp("unsetenv", command) == 0)
		my_unsetenv(args[0]);
}

