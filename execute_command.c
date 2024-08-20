#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

/**
 * execute_command - execute the command
 * Return: nothing
 **/
extern char **environ;

void execute_command(char *command)
{
	int i = 0;
        pid_t pid;
	char *token;
        int status;
        char *argv[64];

	token = strtok(command, " \t");
	while (token != NULL && i < 63)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
        argv[i] = NULL;

        pid = fork();
	if (pid < 0)
	{
		exit(EXIT_FAILURE);
	}
       	if (pid == 0)
       	{
               	if (execve(command, argv, environ) == -1)
               	{
                       	perror("Error with execve");
                       	exit(EXIT_FAILURE);
               	}
       	}
       	else
       	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Waitpid failed");
		}
       	}
}
