#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
*main - prints all arugments without using ac
*@ac: argument counter
*@argv: handle an array of arguments
*Return: (0) Success
*/
int main(int ac, char **argv)
{
(void)ac;
(void)argv;
char *prompt = ("cisfun$ ");
char *string;
size_t n = 0;
printf("%s", prompt);
getline(&string, &n, stdin);
printf("%s\n", string);
free(string);
return (0);
}
