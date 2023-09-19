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
	char *display_prompt = "$ ";
	char *user_input = NULL;
	size_t n = 0;
	char *args[64];
	int interactive;
	(void)argc;
	(void)argv;
	interactive = is_interactive();

	while (1)
	{
		if (interactive && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, display_prompt, _strlen(display_prompt));
		if ((_getline(&user_input, &n, stdin)) == -1)
		{
			perror("No User Input");
			free(user_input);
			exit(EXIT_FAILURE);
		}
		handle_user_input(user_input, args, envp);
	}
	free(user_input);
	return (0);
}
