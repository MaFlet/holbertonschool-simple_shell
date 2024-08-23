#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * print_env - Prints the current environment variables
 *
 * This function iterates through the `environ` array, which contains
 * the environment variables as strings in the format "KEY=VALUE".
 * Each environment variable is printed to the standard output.
 *
 * Return: void
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
