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
	/*int i;*/
	ssize_t getline_status;
	(void)argc;
	(void)argv;
	interactive = is_interactive();

	while (1)
	{
		if (interactive && isatty(STDIN_FILENO))
			write(STDOUT_FILENO, display_prompt, _strlen(display_prompt));
		getline_status = getline(&user_input, &n, stdin);

		if (getline_status == -1)
		{
			if (feof(stdin))
			{
				if (interactive && isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("No User Input");
				/*free(user_input);*/
				exit(EXIT_FAILURE);
			}
		}
		if (user_input[0] != '\n')
			handle_user_input(user_input, args, envp);
	}
	free(user_input);
	return (0);
}
