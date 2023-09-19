#include "main.h"
/**
 * _strlen - Returns the length of a string
 * @string: the string to get the length of
 * Return: the length of @string
 */
int _strlen(char *string)
{
	int len;

	for (len = 0; string[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcpy - Copies a string
 * @dest: Destination valuue
 * @src: Source value
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *original_dest = dest;

	while ((*dest++ = *src++) != '\0')
		;
	return (original_dest);
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination
 * @src: The source string
 * Return: A pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strchr - Locates a character in a string.
 * @string: The string to search.
 * @c: The character to locate.
 *
 * Return: The first occurrence of 'c' in the string
 *         or NULL if the character is not found.
 */
char *_strchr(const char *string, char c)
{
	while (*string != c && *string != '\0')
	{
		string++;
	}
	if (*string == c)
		return ((char *)string);
	else
		return (NULL);
}
