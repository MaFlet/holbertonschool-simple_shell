#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

size_t _strlen(const char *str)
{
	size_t length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

char *_strdup(const char *s)
{
	char *dup;
	size_t len = 0, i = 0;
	if (s == NULL)
	{
		return (NULL);
	}

	while (s[len] != '\0')
	{
		len++;
	}

	dup = (char *)malloc(len + 1);
	if (dup == NULL) 
    	{
		return (NULL);
	}

	while (i <= len)
	{
        	dup[i] = s[i];
		i++;
	}
	return dup;
}

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
    return n == (size_t)-1 ? 0 : (*str1 - *str2);
}

char *_getenv(const char *name)
{
	extern char **environ;
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
	return NULL;
}
