#include "main.h"
/**
 * is_interactive - Check if standard input is from terminal
 *
 * Return: 0 if false, and 1 if true
 */
int is_interactive(void)
{

	if (isatty(STDIN_FILENO) && isatty(SDOUT_FILENO))
	{
	printf("Running interactively.\n");
	}
	else
	{
	printf("Running non-interactively.\n");
	}
}	
