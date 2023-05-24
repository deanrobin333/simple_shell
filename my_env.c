#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * my_env - function that prints the environment
 * Return: void
 */

void my_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

