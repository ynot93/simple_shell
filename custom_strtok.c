#include "main.h"

/**
 * _strtok - Tokenizes a string based on a specified delimiter.
 * @str: The string to be tokenized.
 * @delim: The character that specifies the tokenization.
 *
 * Return: Pointer to tokenized string.
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *token_start;

	if (str != NULL)
		last_token = str;

	if (last_token == NULL || *last_token == '\0')
		return (NULL);

	token_start = last_token;

	while (*last_token != '\0')
	{
		if (_strchr(delim, *last_token) != NULL)
		{
			*last_token = '\0';
			last_token++;
			return (token_start);
		}
		last_token++;
	}
	last_token = NULL;
	return (token_start);
}
