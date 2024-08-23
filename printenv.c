#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * print_env - print environment variables
 * Return: nothing
 **/

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
