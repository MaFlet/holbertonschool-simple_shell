#include "shell.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: An integer less than, equal to, or greater than zero if the first
 * string is found to be less than, to match, or be greater than the
 * second string, respectively.
 */

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
