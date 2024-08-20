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

int main(void)
{
	signal(SIGINT, sigint_handler);

	if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		noninteractive_mode();
	}
	clean_up();
	return (0);
}
