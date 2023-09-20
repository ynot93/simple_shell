#include "main.h"

/**
 * _strspn - Calculates the length of the initial segment of s1
 *                 which consists of characters from second s.
 * @s1: The string to be analyzed.
 * @s2: The characters to match.
 *
 * Return: The length of the initial segment of s1.
 */
size_t _strspn(const char *s1, const char *s2)
{
	const char *i = s1;
	const char *j;
	bool found;

	while (*i != '\0')
	{
		found = false;
		j = s2;

		while (*j != '\0')
		{
			if (*i == *j)
			{
				found = true;
				break;
			}
			j++;
		}
		if (!found)
			break;
		i++;
	}
	return (i - s1);
}
