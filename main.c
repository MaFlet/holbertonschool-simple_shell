#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "shell.h"
char *command_buffer = NULL;
/**
 * clean_up - Frees allocated memory and resets the buffer pointer.
 * Return: nothing
 */
void clean_up(void)
{
	if (command_buffer)
	{
		free(command_buffer);
		command_buffer = NULL;
	}
}
/**
 * sigint_handler - Handles SIGINT signal.
 * @sig: The signal number (not used in this handler).
 * Return: nothing
 */
void sigint_handler(int sig)
{
	(void)sig;
	printf("\nExiting...\n");
	clean_up();
	exit(0);
}
/**
 * main - Entry point of the shell programme
 * Return: Always returns 0.
 **/
int main(void)
{
	signal(SIGINT, sigint_handler);

	if (isatty(STDIN_FILENO))
		interactive_mode();
	else
		noninteractive_mode();
	clean_up();
	return (0);
}
