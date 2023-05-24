#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * main - takes command line arguments
 * @argc: command count
 * @argv: arguments
 * @envp: environment paths
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
		prompt_user(argv, envp);
	exit (0);
}
