#include "main.h"

/**
 * create_path - Create a path by combining a directory and a command.
 * @dir: The directory to be added to path.
 * @cmd: The command to be added to path.
 *
 * Return: A string containing the combined path, or NULL on failure.
 */
char *create_path(const char *dir, const char *cmd)
{
	int cmd_length = strlen(cmd);
	int dir_length = strlen(dir);
	char *path = malloc(cmd_length + dir_length + 2);

	if (path == NULL)
	{
		return (NULL);
	}
	strcpy(path, dir);
	strcat(path, "/");
	strcat(path, cmd);
	return (path);
}
