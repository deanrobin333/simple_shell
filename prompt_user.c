#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * prompt_user - prompts the user for a command
 * @argv: pointer to command line arguments
 * @envp: pointer to environment paths
 * Return: returns void. it starts our simple shell
 * to now take in more than one argument
 */

void prompt_user(char *argv[], char *envp[])
{
	char *command_ptr = NULL, *execve_argv[MAX_COMMANDS];
	ssize_t command_char;
	size_t byte_size = 0;
	int i, child_status;
	pid_t execve_child_pid;

	for (;;)
	{
		if (isatty(0))
			printf("#cisfun$ ");
		command_char = getline(&command_ptr, &byte_size, stdin);
		if (command_char == -1)
		{
			free(command_ptr);
			exit(1);
		}
		for (i = 0; command_ptr[i] != '\0'; i++)
		{
			if (command_ptr[i] == '\n')
				command_ptr[i] = 0;
		}
		execve_argv[0] = strtok(command_ptr, " ");
		for (i = 0; execve_argv[i] != NULL;)
			execve_argv[++i] = strtok(NULL, " ");
		execve_child_pid = fork();
		if (execve_child_pid == -1)
		{
			free(command_ptr);
			exit(1);
		}
		if (execve_child_pid == 0)
		{
			if (execve(execve_argv[0], execve_argv, envp) == -1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			wait(&child_status);
	}
}

