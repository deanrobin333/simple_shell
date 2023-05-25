#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal_number);
/**
 * signal_handler - handles signal input
 * @signal_number: signal received
 * Return: void
 */

void signal_handler(int signal_number)
{
	if (signal_number)
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * main - takes command line arguments
 * @argc: command count
 * @argv: arguments
 * @envp: environment paths
 * Return: 0 on success
 */

int main(int argc, char *argv[], char *envp[])
{

	signal(SIGINT, signal_handler);

	if (argc == 1)
		prompt_user(argv, envp);
	return (0);
}
