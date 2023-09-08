#include "main.h"
/**
 * exec_cmd - executes commands from the input
 * @argv: List of arguments passed
 *
 * Return: Nothing
 */
void exec_cmd(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Cannot execute command");
		}
	}
}
