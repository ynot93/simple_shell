#include "main.h"
/**
 * _strlen - Returns the length of a string
 * @string: the string to get the length of
 * Return: the length of @string
 */
size_t _strlen(char *string)
{
	size_t len;

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

/**
 * _strncmp - Compare two strings.
 * @string1: The first string to be compared.
 * @string2: The second string to be compared.
 * @n: The number of characters to compare.
 *
 * Return: The result between the first differing characters or 0.
 */
int _strncmp(const char *string1, const char *string2, size_t n)
{
	size_t i;

	for (i = 0; i < n && (string1[i] || string2[i]); i++)
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
	return (0);
}
