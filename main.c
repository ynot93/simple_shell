#include "main.h"
/**
 * main - Entry point of the program
 * @argc: The number of arguments passed.
 * @argv: The list of arguments.
 * @envp: The list of environment variables.
 * Return: 0 (Success)
 */
int main(int argc, char **argv, char **envp)
{
	char *display_prompt = "($)";
	char *user_input = NULL;
	size_t n = 0;
	int i;
	char *token;
	char *args[64];
	(void)argc;
	(void)argv;
	is_interactive();

	while (1)
	{
		if (isatty(STDIN_FILENO))
		write(1, display_prompt, _strlen(display_prompt));
		if ((_getline(&user_input, &n, stdin)) == -1)
		{
			perror("No User Input");
			free(user_input);
			exit(EXIT_FAILURE);
		}
		user_input[_strcspn(user_input, "\n")] = 0;
		token = strtok(user_input, " ");
		for (i = 0; token != NULL; i++)
		{
			args[i] = _strdup(token);
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (_strcmp(args[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		if (i > 0)
			exec_cmd(args, envp);

		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
	}
	free(user_input);
	return (0);
}
