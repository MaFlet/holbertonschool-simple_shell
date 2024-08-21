#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

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
