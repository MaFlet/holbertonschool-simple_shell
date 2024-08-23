#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * get_command_path - Get the full path of the command
 * @command: The command to find
 * Return: The path to the command if found, or the original command
 **/

char *get_command_path(const char *command)
{
	if (command[0] != '/' && command[0] != '.')
	return (find_command_path(command));
	return ((char *)command);
}
