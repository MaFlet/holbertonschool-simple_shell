#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * interactive_mode - deal with user input
 * Return: nothing
*/

void interactive_mode(void)
{
	char *command;

	while (1)
	{
		command = read_command(1);
		if (command && *command != '\0')
		{
			execute_command(command);
		}
		free(command);
	}
}
