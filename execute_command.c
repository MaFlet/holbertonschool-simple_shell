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
        pid_t pid;
        int status;
        char *argv[2];
	argv[0] = strdup(command);
	argv[1] = NULL;

        pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		free(argv[0]);
		return;
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
