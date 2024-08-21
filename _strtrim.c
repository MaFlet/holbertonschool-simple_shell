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
	char *end;

	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	       *str == '\r' || *str == '\v' || *str == '\f')
		str++;

	if (*str == 0)
		return (str);

	end = str + _strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' ||
	                     *end == '\r' || *end == '\v' || *end == '\f'))
		end--;


	*(end + 1) = '\0';
	_memmove(str, str, end - str + 2);
	return (str);
}
