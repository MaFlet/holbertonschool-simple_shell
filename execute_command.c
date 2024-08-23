#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
/**
 * execute_command - execute the command
 * @command: take char 'command' as parameter
 * Return: nothing
 **/
void execute_command(char *command)
{
	char *argv[64];
	char *command_path;

	command = _strtrim(command);
	tokenize_command(command, argv);

	if (should_exit(argv))
		return;
	if (handle_builtin_commands(argv))
		return;

	command_path = get_command_path(argv[0]);
	if (!command_path)
		return;
	execute_with_fork(command_path, argv);
}
