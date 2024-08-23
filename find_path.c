#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "shell.h"
/**
 * find_command_path - Finds the full path of a command
 * @command: The command to find
 * Return: The full path of the command or NULL if not found
 */
char *find_command_path(const char *command)
{
	char *path, *dir, *full_path;
	struct stat st;
	size_t len;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return (_strdup(command));
		else
			return (NULL);
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	path = _strdup(path);
	if (!path)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}
	dir = strtok(path, ":");
	while (dir)
	{
		len = _strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			perror("malloc failed"), exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
