#include "shell.h"
#include <unistd.h>
#include <stdio.h>

void clear_environment(void)
{
	static char *empty_environ[] = { NULL };
	environ = empty_environ;
}

