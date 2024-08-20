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
/*
void execute_command(char *command)
{
	char *token;
	int i = 0;
	*char *command_path;
        pid_t pid;
        int status = 0;
        char *argv[64];
	
	if (_strcmp(command, "exit") == 0)
	  {
		free(command);
		exit(status);
	}

	token = strtok(command, " \t");
        while (token != NULL && i < 63)
        {
                argv[i++] = token;
                token = strtok(NULL, " \t");
        }
        argv[i] = NULL;
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
		else if (WIFEXITED(status))
		{
			exit(WEXITSTATUS(status));
		}
	}
	free(command_path);
	free(command);
}*/

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
        char *token, *command_path;
        int status;
        char *argv[64];

        token = strtok(command, " \t");
        while (token != NULL && i < 63)
        {
                argv[i++] = token;
                token = strtok(NULL, " \t");
        }
        argv[i] = NULL;
	
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
	free(command_path);
        free(command);
}
