#ifndef _MAIN_H
#define _MAIN_H
#define MAX_COMMANDS 10
#define PATH_SIZE 40

void prompt_user(char **, char **);
int child(char *command_ptr, char *execve_argv[], char *argv[], char *envp[]);
char *path_checker(char *command_ptr, char *rpath);
ssize_t my_getline(char **command_ptr, size_t *byte_size, FILE *input);
int my_strtok(char *command_ptr, const char *delimiters, char *tokens[]);
char *path_checker2(char *command, char rpath[]);
#endif

