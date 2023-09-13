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
	char *path = find_executable_path(cmd);

	if (path != NULL)
	{
		pid_t = fork();
		if (pid == -1)
		{
			perror("Fork process failed");
		}
		else if (pid == 0)
		{
			if (execve(cmd, argv, envp) == -1)
			{
				perror("Cannot execute command");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		free(path);
	}
	else
	{
		printf("%s: command not found\n", cmd);
	}
}
