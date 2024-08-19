#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

int main(void)
{
	char *command;

	while (1)
	{
		print_prompt();
		command = read_command();
		execute_command(command);
		free(command);
	}
	return (0);
	if (isatty(STDIN_FILENO) == 1)
        printf("Interactive mode\n");
	else
	printf("Not in interactive mode\n");

return (0);
}
