#include "main.h"
/**
 * main - Entry point of the program
 * @argc: The number of arguments passed.
 * @argv: The list of arguments.
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
{
	char *display_prompt = "($)";
	char *user_input = NULL;
	char *original_input = NULL;
	size_t n = 0;
	char *token = NULL;
	int i;

	(void)argc;

	while (1)
	{
		printf("%s", display_prompt);
		if ((getline(&user_input, &n, stdin)) == -1)
		{
			perror("Session expired...");
			free(user_input);
			//free(original_input);
			exit(99);
		}
		original_input = strdup(user_input);
		token = strtok(user_input, " ");

		while (token != NULL)
			token = strtok(NULL, " ");

		printf("%s\n", original_input);
		token = strtok(original_input, " ");

		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
		free(original_input);
	}
	free(user_input);
	return (0);
}
