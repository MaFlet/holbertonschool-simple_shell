#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "shell.h"

char *command_buffer = NULL;

void clean_up()
{
	if (command_buffer)
	{
		free(command_buffer);
		command_buffer = NULL;
	}
}

void sigint_handler(int sig)
{
	(void)sig;
	printf("\nExiting...\n");
	clean_up();
	exit(0);
}

/* Signal handler for SIGINT */

/*void handle_sigint(int sig)
{
    printf("\nCaught signal %d. Type 'exit' to quit the shell.\n", sig);
    printf("cisfun$ ");
    fflush(stdout);      
}*/
int main(void)
{
	char *command;

	signal(SIGINT, sigint_handler);

	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		command = read_command(0);
		if (command && *command == '\0')
		{
			noninteractive_mode();
		}
		else
		{
			free(command);
			noninteractive_mode();
		}
	}
	clean_up();

	return (0);
}
