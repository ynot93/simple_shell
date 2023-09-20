#include "main.h"
/**
 * _strcmp - compares two strings
 * @string1: The first string
 * @string2: The second string
 * Return: The difference
 */
int _strcmp(char *string1, char *string2)
{
	int i;

	for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++)
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
	}
	return (0);
}

/**
 * _strcspn - Calculates the length str1
 * which contain characters not from string2.
 *
 * @string1: The string to be analyzed.
 * @string2: The characters to be excluded.
 *
 * Return: The length of the segment not containing
 * characters from string2.
 */
int _strcspn(char *string1, char *string2)
{
	int len = 0;
	int i;

	while (string1[len] != '\0')
	{
		for (i = 0; string2[i] != '\0'; i++)
		{
			if (string1[len] == string2[i])
				return (len);
		}
		len++;
	}
	return (len);
}

/**
 * _strdup - Duplicate a string.
 * @string: The string to duplicate.
 *
 * Return: A pointer to copy of string, or NULL if memory fails.
 */
char *_strdup(const char *string)
{
	int len = 0;
	int i;
	char *copy;

	if (string == NULL)
		return (NULL);
	while (string[len] != '\0')
		len++;
	copy = (char *)malloc(len + 1);

	if (copy == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		copy[i] = string[i];
	}
	copy[len] = '\0';
	return (copy);
}

/**
 * _atoi - Converts a string to an integer
 * @string: The pointer to convert
 * Return: An integer
 */
int _atoi(char *string)
{
	int sign = 1;
	int number = 0;
	int digit;
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '-')
			sign *= -1;
		if (string[i] >= '0' && string[i] <= '9')
		{
			digit = string[i] - '0';
			number = number * 10 + sign * digit;
			if (string[i + 1] < '0' || string[i + 1] > '9')
				break;
		}
	}
	return (number);
}
