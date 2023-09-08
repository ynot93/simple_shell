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
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		if (execve(cmd, argv, envp) == -1)
		{
			perror("Cannot execute command");
		}
	}
}
