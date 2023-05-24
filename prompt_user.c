#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>
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
	char *command_ptr = NULL, *execve_argv[MAX_COMMANDS], *path, rpath[PATH_SIZE];
	ssize_t command_char;
	size_t byte_size = 0;
	int i;
	int piped_input = !isatty(STDIN_FILENO);

	for (;;)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		command_char = my_getline(&command_ptr, &byte_size, stdin);
		if (command_char == -1)
		{
			free(command_ptr);
			exit(1); }
		for (i = 0; command_ptr[i] != '\0'; i++)
		{
			if (command_ptr[i] == '\n')
				command_ptr[i] = '\0'; }
		if (*command_ptr != '\0')
		{
			my_strtok(command_ptr, " ", execve_argv);
			if (strcmp("exit", *execve_argv) == 0 &&
					*(execve_argv + 1) != NULL)
				my_exit(execve_argv[1]);
			if (strcmp("exit", *execve_argv) == 0)
				break;
			if (strcmp("env", *execve_argv) == 0)
			{
				my_env();
				continue; }
			path = path_checker(*execve_argv, rpath);
			if (path != NULL)
				*execve_argv = path;
			child(command_ptr, execve_argv, argv, envp); }
		if (piped_input && command_char < 1)
			break;
	}
	free(command_ptr);
	exit(0);
}
