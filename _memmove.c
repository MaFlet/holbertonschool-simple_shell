#include <stddef.h>
#include "shell.h"

/**
 * _memmove - copy a block memory from one location to another
 * @dest: pointer of destination array
 * @src: second pointer that denote the source of data to be copied
 * @n: number of char
 * Return: A pointer to the trimmed string
 */

void *_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d = dest;
	const unsigned char *s = src;

	if (d == s)
	{
		return (dest);
	}

	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
