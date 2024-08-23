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
extern char **environ;

/* simple shell prototypes */
char *read_command(int interactive);
void execute_command(char *command);
void interactive_mode(void);
void noninteractive_mode(void);
char *find_command_path(const char *command);
void tokenize_command(char *command, char **argv);

/* main.c protypes */
void clean_up(void);
void sigint_handler(int sig);

/* helper prototypes */
char *_strdup(const char *s);
size_t _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_getenv(const char *name);
char *_strtrim(char *str);
size_t _strcspn(const char *s, const char *reject);
void *_memmove(void *dest, const void *src, size_t n);
void print_env(void);

#endif /* SHELL */
