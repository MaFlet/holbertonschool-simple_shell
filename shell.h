#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stddef.h>
extern char *command_buffer;

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
void clean_up();
void sigint_handler(int sig);
int _strcmp(const char *s1, const char *s2);
size_t _strcspn(const char *s, const char *reject);

#endif /* SHELL */
