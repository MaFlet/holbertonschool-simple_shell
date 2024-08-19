#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * read_command - Reads a command from standard input.
 *
 * Return: A pointer to the command string.
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}
		perror("getline");
		exit(EXIT_FAILURE);
	}

	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
