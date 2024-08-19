#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void)
{
	char *command;

	while (1)
	{
		print_prompt();
		command = read_command();
		if (command && *command)
		{
			execute_command(command);
		}
		free(command);
	}
	return (0);
}
