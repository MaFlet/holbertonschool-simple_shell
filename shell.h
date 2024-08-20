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

char *read_command(int interactive);
void execute_command(char *command);
char *_strtrim(char *str);
void interactive_mode(void);
void noninteractive_mode(void);
void clean_up();
void sigint_handler(int sig);

char *_getenv(const char *name);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
size_t _strcspn(const char *s, const char *reject);
void *_memmove(void *dest, const void *src, size_t n);
char *find_command_path(char *command);
void tokenize_command(char *command, char **argv);
/*void handle_sigint(int sig);*/

#endif /* SHELL */
