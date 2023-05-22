#ifndef _MAIN_H
#define _MAIN_H
#define MAX_COMMANDS 10

void prompt_user(char **, char **);
void child(char *command_ptr, char *execve_argv[], char *argv[], char *envp[]);
#endif

