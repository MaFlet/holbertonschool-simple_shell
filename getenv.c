#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
/**
*_getenv - gets an environment variable
*@name - name of variable
*Return: environmental variable or NULL if otherwise
*/
char *_getenv(const char *name)
{
size_t name_var, value_p;
char *value;
int a, b, c;
name_var = strlen(name);
for (a = 0; environ[a]; a++)
{
if (strncmp(name, environ[a], name_var) == 0)
{
value_p = strlen(environ[a]) - name_var;
value = malloc(sizeof(char) * value_p);
if (!value)
{
free(value);
perror("Error: unable to allocate memory");
return (NULL);
}
b = 0;
for (c = name_var + 1; environ[a][c]; c++, b++)
{
value[b] = environ[a][c];
}
value[b] = '\0';
return (value);
}
}
return (NULL);
}

