#include "main.h"
/**
 * print_env - Prints the environment variables.
 * @envp: Array to store the environment variables.
 *
 * Return: Nothing.
 */
void print_env(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
