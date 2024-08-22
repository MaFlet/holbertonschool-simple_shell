#include <stddef.h>
#include "shell.h"

/**
* _strcspn - finds the first occurrence of a character in
* string1 that belongs to the set of characters that is specified by string2
* @s: string
* @reject: the charactor to match
* Return: A pointer to the trimmed string
*/

size_t _strcspn(const char *s, const char *reject)
{
	const char *p;
	const char *r;

	for (p = s; *p; p++)
	{
		for (r = reject; *r; r++)
		{
			if (*p == *r)
			{
				return (p - s);
			}
		}
	}
	return (p - s);
}
