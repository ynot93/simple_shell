#include "main.h"
/**
 * find_executable_path - Finds the executable in PATH.
 * @cmd: The executable command.
 * @original_path: The original PATH variable.
 * Return: The full path to the executable if found,
 *         NULL if not.
 */
char *find_executable_path(char *cmd, char *original_path)
{
	char *copy_path;
	char *ptr;
	char *path;
	struct stat file_info;

	copy_path = strdup(original_path);
	ptr = strtok(copy_path, ":");

	while (ptr != NULL)
	{
		path = malloc(strlen(ptr) + strlen(cmd) + 2);

		strcpy(path, ptr);
		strcat(path, "/");
		strcat(path, cmd);
		strcat(path, "\0");
		if (stat(path, &file_info) == 0)
		{
			free(copy_path);
			return (path);
		}
		free(path);
		ptr = strtok(NULL, ":");
	}
	free(copy_path);

	if (stat(cmd, &file_info) == 0)
	{
		return (cmd);
	}
	return (NULL);
}
