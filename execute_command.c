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
	char *command_path;
        pid_t pid;
        int status;
        char *argv[64];
	
	if (_strcmp(command, "exit") == 0)
	{
		free(command);
		exit(status);
	}

	tokenize_command(command, argv);
	command_path = find_command_path(argv[0]);

	if (command_path == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", argv[0]);
		return;
	}

        pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
       	if (pid == 0)
       	{
               	if (execve(argv[0], argv, environ) == -1)
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
	
		else
		{
			if(WIFEXITED(status))
			{
				exit(WEXITSTATUS(status));
			}
		}
	}
free(command_path);

}
