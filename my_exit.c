#include <stdio.h>
#include <stdlib.h> 
#include "main.h"

void my_exit(char *argv)
{
    if (argv != NULL)
    {
        int status = atoi(argv);
        exit(status);
    }
    else
    {
        exit(0);
    }
}

