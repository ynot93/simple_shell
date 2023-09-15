#include "main.h"

/**
 * _getline - Get line input from user.
 * @line_ptr: Store the address of the line of text read.
 * @n: Size of the buffer.
 * @stream: Where the input is read from.
 *
 * Return: Number of characters read on success and -1 on failure.
 */
ssize_t _getline(char **line_ptr, size_t *n, FILE *stream)
{
	static char *buffer;
	static buffer_size;
	size_t i;
	int ch;
	char *temp;

	buffer = NULL;
	buffer_size = 0;
	i = 0;

	if (*line_ptr == NULL || *n == 0)
	{
		if (buffer == NULL)
		{
			buffer_size = 128;
			buffer = (char *)malloc(sizeof(buffer_size));
			if (buffer == NULL)
			{
				perror("Memory allocation failure");
				free(buffer);
				return (-1);
			}
		}
		*n = buffer_size;
		*line_ptr = buffer;
	}

	while ((ch = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			temp = (char *)realloc(*line_ptr, *n);
			if (temp == NULL)
			{
				perror("Memory allocation failure");
				return (-1);
			}
			*line_ptr = temp;
		}
		(*line_ptr)[i++] = ch;

		if (ch == '\n')
		{
			(*line_ptr)[i] = '\0';
			return (i);
		}
	}
	if (i == 0)
		return (-1);
	(*line_ptr)[i] = '\0';
	return (1);
}
