#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * my_exit - handles arguments for exit
 * @argv: pointer to commands
 * Return: void
 */

void my_exit(char *argv)
{
	int status;

	if (argv != NULL)
	{
		status = atoi(argv);
		exit(status);
	}
	else
		exit(EXIT_SUCCESS);
}

