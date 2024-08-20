#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

int main(void)
{
	if (isatty(fileno(stdin)))
	{
		interactive_mode();
	}
	else
	{
		noninteractive_mode();
	}
	return (EXIT_SUCCESS);
}
