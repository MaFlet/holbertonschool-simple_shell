#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shell.h"

/**
 * _strtrim - Trims leading and trailing whitespace from a string
 * @str: The string to be trimmed
 * Return: A pointer to the trimmed string
 */

char *_strtrim(char *str)
{
	char *start = str;
	char *end;

	while (*start == ' ' || *start == '\t' || *start == '\n' ||
		*start == '\r' || *start == '\v' || *start == '\f')
	{
		start++;
	}

	if (*start == 0)
	{
		*str = '\0';
		return (str);
	}

	end = start + _strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t' || *end == '\n' ||
		*end == '\r' || *end == '\v' || *end == '\f'))
	{
		end--;
	}

	*(end + 1) = '\0';
	if (start != str)
	{
		_memmove(str, start, end - start + 2);
	}
	return (str);
}
