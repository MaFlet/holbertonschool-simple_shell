#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *read_command(int interactive) {
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t input;

	if (interactive)
	{
		printf("cisfun$ ");
	}
	input = getline(&command, &bufsize, stdin);
	if (input == -1)
	{
		if (input == EOF)
		{
			if (interactive)
			{
				printf("\n");
			}
			free(command);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed...");
			free(command);
			exit(EXIT_FAILURE);
		}	
	}

	if (input > 0 && command[input - 1] == '\n')
	{
		command[input - 1] = '\0';
	}
	command = _strtrim(command);
	return(command);
}
