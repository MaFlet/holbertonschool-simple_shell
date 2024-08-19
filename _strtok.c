#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <shell.h>
/**
*main - tokenize strings for command PATH line
*@string - string to be tokenize
*@delimiter - delimiter/symbol to searck to tokenize string
*Return: (0) Success
*/
char *strtok(char *string, const char *delimiter)
{
	unsigned int i = 0;
	static char *tokenize_string
	static char *new_token;
	if (string != NULL)
		new_token = string;
	tokenize_string = new_token;
	if (tokenize_string == NULL)
		return (NULL);
	for (i = 0; tokenize_string[i] != '\0'; i++)
	{
		if (search_rightdelim(tokenize_string[i], delimiter) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == ",")
	{
		new_token = NULL;
		return (NULL);
	}
	tokenize_string = new_token + i;
	new_token = tokenize_string;
	for (i = 0; new_token[i] != '\0', i++)
	{
		if (search_rightdelim(new_token[i], delimiter) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (tokenize_string);
}
