#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <stddef.h>

/**
 * read_command - Reads a command from standard input.
 * @interactive: If non-zero, prompts the user with a shell prompt.
 *
 * Return: A pointer to the trimmed command string, or NULL if the input
 *         is empty or only contains whitespace.
 */

char *read_command(int interactive)
{
        size_t bufsize = 0, len;
        ssize_t input;

        if (interactive)
                printf("cisfun$ ");

        input = getline(&command_buffer, &bufsize, stdin);
        if (input == -1)
        {
                if (input == EOF)
                {
                        if (interactive)
                        {
                                printf("\n");
                        }
                        free(command_buffer);
                        command_buffer = NULL;
                        exit(EXIT_SUCCESS);
                }
                else
                {
                        perror("getline failed...");
                        free(command_buffer);
                        command_buffer = NULL;
                        exit(EXIT_FAILURE);
                }
        }

        len = _strcspn(command_buffer, "\n");
        command_buffer[len] = '\0';
        command_buffer = _strtrim(command_buffer);
        if (command_buffer == NULL || *command_buffer == '\0')
        {
                free(command_buffer);
                return NULL;
        }
        {
                command_buffer[input - 1] = '\0';
        }
        command_buffer = _strtrim(command_buffer);
        return(command_buffer);
}
