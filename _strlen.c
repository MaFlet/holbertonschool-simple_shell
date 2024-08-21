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
