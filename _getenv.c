#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

/**
* _getenv - get environment variables
* @name: name of env variable
* Return: environ or NULL
*/

char *_getenv(const char *name)
{
	int i = 0;
	size_t len = _strlen(name);

	if (name == NULL || len == 0)
	{
		return (NULL);
	}

	while (environ[i])
	{
		if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
