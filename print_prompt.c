#include "shell.h"

/**
 * print_prompt - Prints the shell prompt
 *
 * Return: 1 if running in interactive mode, 0 otherwise.
 */

int print_prompt(void)
{
	int interactive_mode = 0;

	if (isatty(STDIN_FILENO) == 1 && isatty(STDOUT_FILENO) == 1)
		interactive_mode = 1;

	if (interactive_mode == 1)
		write(STDERR_FILENO, "$ ", 2);

	return (interactive_mode);
}
