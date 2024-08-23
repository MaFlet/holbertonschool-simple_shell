#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * execute_with_fork - execute fork
 * @command_path: take char 'command_path'as parameter
 * @argv: take 'argv' as parameter
 * Return: nothing
 **/
void execute_with_fork(char *command_path, char *argv[])
{
	pid_t pid;
	int status;

	if (access(command_path, X_OK) == 0)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(command_path, argv, environ) == -1)
			{
				perror("Error with execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
	else
		fprintf(stderr, "Command does not exist: %s\n", command_path);
}

