#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

/**
* _strncmp - function to compare 2 strings
* @str1: first string
* @str2: second string
* @n: number of characters
* Return: A pointer to the trimmed string
*/

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (n == (size_t)-1 ? 0 : (*str1 - *str2));
}
