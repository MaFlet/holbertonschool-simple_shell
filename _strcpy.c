#include <stdio.h>
#include "shell.h"

char *_strcpy(char *dest, const char *src)
{
    char *dest_ptr = dest;

    while (*src != '\0')
    {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }

    *dest_ptr = '\0';

    return dest;
}

