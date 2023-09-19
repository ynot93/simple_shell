#include "main.h"

/**
 * handle_user_input - Parse user input and handle commands.
 * @user_input: User input string.
 * @args: Array to store arguments.
 * @envp: Array of environment variables.
 */
void handle_user_input(char *user_input, char **args, char **envp)
{
	int i;
	char *token;

	user_input[_strcspn(user_input, "\n")] = 0;
	token = _strtok(user_input, " ");
	for (i = 0; token != NULL; i++)
	{
		args[i] = _strdup(token);
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1])
		{
			int status = _atoi(args[1]);

			exit(status);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else if (_strcmp(args[0], "setenv") == 0)
		handle_setenv(args[1], args[2]);
	else if (_strcmp(args[0], "unsetenv") == 0)
		handle_unsetenv(args[1]);
	else
	{
		if (i > 0)
			exec_cmd(args, envp);
	}
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
}
