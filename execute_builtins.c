#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * should_exit - Checks if the command is "exit"
 * and terminates the process if true.
 * @argv: The argument vector containing the command and its arguments.
 * Return: Always returns 0
 */
int should_exit(char *argv[])
{
	if (argv[0] && _strncmp(_strtrim(argv[0]), "exit", 4) == 0 && argv[1] == NULL)
	{
		free(argv[0]);
		exit(0);
	}
	return (0);
}
/**
 * handle_builtin_commands - Handles built-in commands such as "env".
 * @argv: The argument vector containing the command and its arguments
 * Return: 1 if it's 'env' or  0 otherwise.
 */
int handle_builtin_commands(char *argv[])
{
	if (_strncmp(argv[0], "env", 3) == 0 && argv[0][3] == '\0')
	{
		print_env();
		return (1);
	}
	return (0);
}
