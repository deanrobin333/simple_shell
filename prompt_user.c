#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * child - function to create child process
 * @command_ptr: pointer containing commands from stdin
 * @execve_argv: pointer containing token commands
 * @argv: pointer to array of arguments
 * @envp: pointer to environments
 * Return: void
 */

int child(char *command_ptr, char *execve_argv[], char *argv[], char *envp[])
{
	pid_t execve_child_pid;
	int child_status;

	execve_child_pid = fork();
	if (execve_child_pid == -1)
	{
		free(command_ptr);
		perror("fork");
		exit(1);
	}
	if (execve_child_pid == 0)
	{
		if (execve(execve_argv[0], execve_argv, envp) == -1)
		{
			printf("%s: No such file or directory\n", argv[0]);
			exit(0);
		}
	}
	else
		wait(&child_status);
	return (WIFEXITED(child_status) && WEXITSTATUS(child_status));

}

/**
 * prompt_user - prompts the user for a command
 * @argv: pointer to command line arguments
 * @envp: pointer to environment paths
 * Return: returns void. it starts our simple shell
 * to now take in more than one argument
 */

void prompt_user(char *argv[], char *envp[])
{
	char *command_ptr = NULL, *execve_argv[MAX_COMMANDS], *path, rpath[PATH_SIZE];
	ssize_t command_char;
	size_t byte_size = 0;
	int i;

	for (;;)
	{
		if (isatty(0))
			printf("#cisfun$ ");
		command_char = getline(&command_ptr, &byte_size, stdin);
		if (command_char == -1)
		{
			free(command_ptr);
			perror("getline");
			exit(1);
		}
		for (i = 0; command_ptr[i] != '\0'; i++)
		{
			if (command_ptr[i] == '\n')
				command_ptr[i] = '\0';
		}
		if (*command_ptr != '\0')
		{
			execve_argv[0] = strtok(command_ptr, " ");
			for (i = 0; execve_argv[i] != NULL;)
				execve_argv[++i] = strtok(NULL, " ");
			path = path_checker(*execve_argv, rpath);
			if (path != NULL)
				*execve_argv = path;
			child(command_ptr, execve_argv, argv, envp);
		}
	}
	free(command_ptr);
}

