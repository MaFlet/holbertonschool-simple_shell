#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

char *normalize_path(const char *path)
{
    char resolved_path[MAX_PATH];
    char *normalized_path;
    char *ptr;
    char *token;
    char *path_copy;

    if (realpath(path, resolved_path) == NULL)
    {
        perror("Error resolving path");
        return NULL;
    }
    normalized_path = strdup(resolved_path);
    if (normalized_path == NULL)
    {
        perror("Error duplicating path");
        return NULL;
    }
    ptr = normalized_path;
    while ((token = strtok(ptr, "/")) != NULL)
    {
        if (strcmp(token, ".") != 0 && strcmp(token, "..") != 0)
        {
            strcat(ptr, "/");
            strcat(ptr, token);
        }
        ptr += strlen(token) + 1;
    }

    return normalized_path;
}
