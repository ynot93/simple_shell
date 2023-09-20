#include "main.h"
/**
 * is_interactive - Check if standard input is from terminal
 *
 * Return: 0 if false, and 1 if true
 */
int is_interactive(void)
{

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		/*write(STDOUT_FILENO, "Running interactively.\n", 23);*/
		return (1);
	}
	else
	{
		/*write(STDOUT_FILENO, "Running non-interactively.\n", 27);*/
		return (0);
	}
}
