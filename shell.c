#include <stdio.h>
#include "main.h"
/**
 * main - takes command line arguments
 * @argc: command count
 * @argv: arguments
 * @envp: environment paths
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{
	my_setenv("MY_VAR", "Shell_is_tough");
	if (argc == 1)
		prompt_user(argv, envp);
	my_unsetenv("MY_VAR");
	return (0);
}
