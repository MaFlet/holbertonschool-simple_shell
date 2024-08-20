#include <stdio.h>
#include <string.h>
#include <stddef.h>

extern char **environ;

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

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
		{
			return (unsigned char)*s1 - (unsigned char)*s2;
		}
		s1++;
		s2++;
	}
	return 0;
}

char *_getenv(const char *name)
{
        int i = 0;
        size_t len = _strlen(name);

        while (environ[i])
	{
                if(_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
                {
                        return (environ[i] + len + 1);
                }
                i++;
        }
        return (NULL);

}
