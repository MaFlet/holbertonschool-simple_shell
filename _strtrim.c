/**
 * _strtrim - Trims leading and trailing whitespace from a string.
 * @str: The string to be trimmed.
 *
 * Return: A pointer to the trimmed string.
 */
char *_strtrim(char *str)
{
	char *end;

	/* Trim leading whitespace */
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
	       *str == '\r' || *str == '\v' || *str == '\f')
		str++;

	if (*str == 0)  /* All spaces or empty string? */
		return (str);

	/* Trim trailing whitespace */
	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n' ||
	                     *end == '\r' || *end == '\v' || *end == '\f'))
		end--;

	/* Null-terminate the trimmed string */
	*(end + 1) = '\0';

	return (str);
}
