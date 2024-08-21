#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

/**
 * execute_command - execute the command
 * command: take char 'command' as parameter
 * Return: nothing
 **/

extern char **environ;

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

void execute_command(char *command)
{
	pid_t pid;
	int status = 0;
	char *argv[64];
	char *command_path;

	command = _strtrim(command);	
	tokenize_command(command, argv);

	if (argv[0] == NULL)
	{
		return;
	}

	if (argv[0] && _strncmp(_strtrim(argv[0]), "exit", 4) == 0 && argv[1] == NULL)
   	{
		free(argv[0]);
		exit(status);
	}

	if (_strncmp(argv[0], "env", 3) == 0 && argv[0][3] == '\0')
	{
		print_env();
		return;
	}
	if (argv[0][0] != '/' && argv[0][0] != '.')
	{
		command_path = find_command_path(argv[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
			status = 127;
			return;
		}
	}
	else
	{
		command_path = argv[0];
	}

	if (access(command_path, X_OK) == 0)
	{
	
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			free(command_path);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(command_path, argv, environ) == -1)
			{
				perror("Error with execve");
				free(command_path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Waitpid failed");
			}
			if (WIFEXITED(status))
			{
				status = WEXITSTATUS(status);
			}
		}
	}
	else
	{
		fprintf(stderr, "Command not executable or does not exist: %s\n", command_path);
		status = 126;
	}

	if (command_path != argv[0])
	{
		free(command_path);
	}
}
