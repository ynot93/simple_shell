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
	size_t n = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", display_prompt);
		if ((getline(&user_input, &n, stdin)) == -1)
		{
			perror("Incorrect user input");
			free(user_input);
			exit(99);
		}
		printf("%s\n", user_input);
	}
	free(user_input);
	return (0);
}
