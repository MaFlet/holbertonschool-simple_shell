#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * interactive_mode - deal with user input
 * Return: nothing
*/

void noninteractive_mode(void)
{	
	char *command;

	while (1)
	{
		command = read_command(0);
		if (command && *command != '\0')
		{
			execute_command(command);
		}
		free(command);
	}
}
