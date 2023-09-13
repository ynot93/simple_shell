#include "main.h"
/**
 * find_executable_path - Finds the executable in PATH.
 * @cmd: The executable command.
 *
 * Return: The full path to the executable if found,
 *         NULL if not.
 */
char *find_executable_path(char *cmd)
{
	char *original_path = getenv("PATH");
	char *constructed_path;
	char *copy_path;
	char *ptr;
	struct stat file_info;

	if (original_path == NULL)
		return (NULL);

	copy_path = strdup(original_path);
	ptr = copy_path;

	while (*copy_path)
	{
		if (*copy_path == ':')
		{
			copy_path = "\0";
			constructed_path = create_path(ptr, cmd);

			if (constructed_path != NULL && stat(constructed_path, &file_info) == 0)
			{
				free(copy_path);
				return (constructed_path);
			}
			free(constructed_path);
			ptr = copy_path + 1;
		}
		copy_path++;
	}
	//free(copy_path);

	if (stat(cmd, &file_info) == 0)
		return (cmd);

	return (NULL);
}
