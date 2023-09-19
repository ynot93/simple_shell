#include "main.h"
/**
 * handle_setenv - Initialize a new envronment variable.
 * @var_name: The name of the variable.
 * @var_value: The value assigned to the name variable.
 *
 * Return: -1 on error, 0 on success.
 */
int handle_setenv(char *var_name, char *var_value)
{
	char msg[] = "Environment variable set.\n";
	char msg1[] = "Failed to set environment variable..\n";

	if (setenv(var_name, var_value, 1) == 0)
	{
		write(STDOUT_FILENO, msg, _strlen(msg));
		return (0);
	}
	else
	{
		write(STDERR_FILENO, msg1, _strlen(msg1));
		return (-1);
	}
}

/**
 * handle_unsetenv - Initialize a new envronment variable.
 * @var_name: The name of the variable.
 *
 * Return: -1 on error, 0 on success.
 */
int handle_unsetenv(char *var_name)
{
	char msg[] = "Environment variable unset.\n";
	char msg1[] = "Failed to unset environment variable.\n";

	if (unsetenv(var_name) == 0)
	{
		write(STDOUT_FILENO, msg, _strlen(msg));
		return (0);
	}
	else
	{
		write(STDERR_FILENO, msg1, _strlen(msg1));
		return (-1);
	}
}
