#include "shell.h"
#include <string.h>

/**
 * tokenize_command - function that tokenize a string
 * @command: pointer to the command
 * @argv: array of arguments
 */

void tokenize_command(char *command, char **argv)
{
	int i = 0;
	char *token;

	token = strtok(command, " \t\n");
	while (token != NULL && i < 63)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;
}
