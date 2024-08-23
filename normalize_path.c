#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_PATH 1024

char *normalize_path(const char *path)
{
    char *normalized_path = malloc(MAX_PATH);
    char *token;
    char *path_copy = strdup(path);
    char *components[MAX_PATH];
    int top = -1, i;

    if (!normalized_path || !path_copy)
    {
        perror("Error allocating memory");
        free(normalized_path);
        free(path_copy);
        return NULL;
    }
    token = strtok(path_copy, "/");
    while (token != NULL)
    {
        if (strcmp(token, "..") == 0)
        {
            if (top >= 0)
                top--;
        }
        else if (_strcmp(token, ".") != 0 && _strcmp(token, "") != 0)
        {
            components[++top] = token;
        }
        token = strtok(NULL, "/");
    }

    normalized_path[0] = '\0';
    for (i = 0; i <= top; i++)
    {
        _strcat(normalized_path, "/");
        _strcat(normalized_path, components[i]);
    }

    if (top == -1)
    {
        _strcpy(normalized_path, "/");
    }

    free(path_copy);
    return (normalized_path);
}

