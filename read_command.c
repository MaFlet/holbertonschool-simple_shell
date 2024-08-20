#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <stddef.h>

char *read_command(int interactive)
{
	/*char *command = NULL;*/
	size_t bufsize = 0;
	ssize_t input;
	size_t len;

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
                        command_buffer = NULL;
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed...");
			free(command_buffer);
                        command_buffer = NULL;
			exit(EXIT_FAILURE);
		}	
	}


	len = _strcspn(command_buffer, "\n");
	command_buffer[len] = '\0';
/*	if (input > 0 && command_buffer[input - 1] == '\n')
	{
		command_buffer[input - 1] = '\0';
	}
*/
	command_buffer = _strtrim(command_buffer);
	return(command_buffer);
}
