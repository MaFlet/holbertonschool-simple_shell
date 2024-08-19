#include <stdio.h>
#include "shell.h"

int main(void)
{
	char *command;

	while (1)
	{
		print_prompt();
		command = read_command();
		execute_command(command);
	}
	return (0);
}
