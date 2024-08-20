#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/*typedef struct name
{
	code here
} struct_name; */

/*void print_prompt(void);*/
char *read_command(int interactive);
void execute_command(char *command);
char *_strtrim(char *str);
void interactive_mode(void);
void noninteractive_mode(void);

#endif /* SHELL */
