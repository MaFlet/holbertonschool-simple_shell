#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *read_command(int interactive)
{
	/*char *command = NULL;*/
	size_t bufsize = 0;
	ssize_t input;

	if (interactive)
	{
		printf("cisfun$ ");
	}
	input = getline(&command_buffer, &bufsize, stdin);
	if (input == -1)
	{
		if (input == EOF)
		{
			if (interactive)
			{
				printf("\n");
			}
			free(command_buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed...");
			free(command_buffer);
			exit(EXIT_FAILURE);
		}	
	}

	if (input > 0 && command_buffer[input - 1] == '\n')
	{
		command_buffer[input - 1] = '\0';
	}
	command_buffer = _strtrim(command_buffer);
	return(command_buffer);
}
