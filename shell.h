#ifndef SHELL
#define SHELL

/*typedef struct name
{
	code here
} struct_name; */

void print_prompt(void);
char *read_command(void);
void execute_command(char *command);
void interactive();
void non_interactive();

#endif /* SHELL */
