#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

char *find_command_path(const char *command)
{
	char *path, *dir, *full_path;
	struct stat st;
	size_t len;

	path = getenv("PATH");
	if (!path)
	{
		return NULL;
	}

	path = strdup(path);
	if (!path)
	{
		perror("strdup failed");
		exit(EXIT_FAILURE);
	}

	dir = strtok(path, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}

	snprintf(full_path, len, "%s/%s", dir, command);

	if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		free(path);
		return full_path;
	}
	free(full_path);
	dir = strtok(NULL, ":");
	}

	free(path);
	return NULL;
}
