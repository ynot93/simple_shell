#include "main.h"

static char *buffer;
static size_t buffer_size;

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
	size_t i;
	char ch;
	char buffer[1];
	ssize_t bytes_read;
	int fd = fileno(stream);
	struct stat file_info;

	i = 0;

	init_buffer(line_ptr, n);

	if (fstat(fd, &file_info) == -1)
	{
		perror("Failed to get file information");
		return (-1);
	}
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		ch = buffer[0];
		extend_buffer(line_ptr, n, i);
		(*line_ptr)[i++] = ch;
		if (ch == '\n')
		{
			(*line_ptr)[i] = '\0';
			return (i);
		}
	}
	if (bytes_read < 0)
	{
		perror("Read error");
		return (-1);
	}
	if (i == 0)
		return (-1);
	(*line_ptr)[i] = '\0';
	return (1);
}

/**
 * init_buffer - Allocates initial buffer.
 * @line_ptr: Pointer to the line buffer.
 * @n: Pointer to the size of the buffer.
 */
void init_buffer(char **line_ptr, size_t *n)
{
	if (*line_ptr == NULL || *n == 0)
	{
		if (buffer == NULL)
		{
			buffer_size = 128;
			buffer = (char *)malloc(sizeof(buffer_size));
			if (buffer == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
		}
		*n = buffer_size;
		*line_ptr = buffer;
	}
}

/**
 * extend_buffer - Expands the buffer.
 * @line_ptr: Pointer to the line buffer.
 * @n: Pointer to the size of the buffer.
 * @i: Current index in the buffer.
 */
void extend_buffer(char **line_ptr, size_t *n, size_t i)
{
	char *temp;

	if (i >= *n - 1)
	{
		*n *= 2;
		temp = (char *)realloc(*line_ptr, *n);
		if (temp == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		*line_ptr = temp;
	}
}
