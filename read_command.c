#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *read_command(void) {
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t input;

	input = getline(&command, &bufsize, stdin);
	if (input == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}	
	}

	if (input > 0 && command[input - 1] == '\n')
	{
		command[input - 1] = '\0';
	}
	return(command);
}
