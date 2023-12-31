#include "main.h"
#include <unistd.h>

/**
 * exec_cmd - executes commands from the input
 * @argv: List of arguments passed
 * @envp: Environment variables
 *
 * Return: Nothing
 */
void exec_cmd(char **argv, char **envp)
{
	char *cmd, *path;

	cmd = argv[0];
	path = getenv("PATH");

	if (path != NULL)
	{
		char *full_path = find_executable_path(cmd, path);

		if (full_path != NULL)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("Fork process failed");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(full_path, argv, envp) == -1)
				{
					perror("Cannot execute command");
					exit(EXIT_FAILURE);
				}
				free(full_path);
			}
			else
			{
				wait(NULL)
				free(full_path);
			}
		}
		else
		{
			write(2, cmd, _strlen(cmd));
			write(2, ": command not found\n", 20);
			exit(EXIT_FAILURE);
		}
	}
}
