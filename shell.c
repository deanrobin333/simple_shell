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
		exit(0);
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
	char *command_ptr = NULL;

	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTERM, signal_handler);

	if (argc == 1)
		command_ptr = prompt_user(argv, envp);
	if (command_ptr != NULL)
		free(command_ptr);
	exit(0);
}
