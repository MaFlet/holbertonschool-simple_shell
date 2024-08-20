#include "shell.h"
#include <string.h>

void tokenize_command(char *command, char **argv)
{
	int i = 0;
	char *token;

	token = strtok(command, " \t");
	while (token != NULL && i < 63)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;
}
