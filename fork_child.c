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
		return (-1);
	}
	if (execve_child_pid == 0)
	{
		if (execve(execve_argv[0], execve_argv, envp) == -1 &&
				strcmp("exit", *execve_argv) == 0)
			return (WIFEXITED(child_status) && WEXITSTATUS(child_status));
		if (execve(execve_argv[0], execve_argv, envp) == -1)
		{
			printf("%s: No such file or directory\n", argv[0]);
		}
	}
	else
		wait(&child_status);
	return (WIFEXITED(child_status) && WEXITSTATUS(child_status));

}
