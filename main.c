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

	(void)argc;

	while (1)
	{
		printf("%s", display_prompt);
		if ((getline(&user_input, &n, stdin)) == -1)
		{
			perror("Session expired...");
			free(user_input);
			exit(99);
		}
		user_input[strcspn(user_input, "\n")] = 0;
		token = strtok(user_input, " ");
		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
		if (i > 0)
		{
			exec_cmd(argv, envp);
		}
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
	}
	free(user_input);
	return (0);
}
