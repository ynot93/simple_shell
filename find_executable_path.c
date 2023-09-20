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
	char *result = NULL;
	struct stat file_info;

	copy_path = _strdup(original_path);
	ptr = strtok(copy_path, ":");

	while (ptr != NULL)
	{
		path = malloc(_strlen(ptr) + _strlen(cmd) + 2);

		_strcpy(path, ptr);
		_strcat(path, "/");
		_strcat(path, cmd);
		_strcat(path, "\0");
		if (stat(path, &file_info) == 0)
		{
			result = _strdup(path);
			free(copy_path);
			free(path);
			return (result);
		}
		free(path);
		ptr = strtok(NULL, ":");
	}
	free(copy_path);

	if (stat(cmd, &file_info) == 0)
	{
		return (strdup(cmd));
	}
	return (NULL);
}
