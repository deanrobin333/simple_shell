#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
		prompt_user(argv, envp);
	return(0);
}
