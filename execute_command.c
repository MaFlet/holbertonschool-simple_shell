#include "shell.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * execute_command - execute the command
 * Return: nothing
 **/

extern char **environ;

void execute_command(char *command)
{
        pid_t pid;
        int status;
        char *argv[] = {command, NULL};

        pid = fork();
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
                perror("Fork failed");
                wait(&status);
        }
}
