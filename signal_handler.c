#include "shell.h"

/**
 * signal_handler - Handles the signal interference
 *
 * @n: The signal number
 */

void signal_handler(int n)
{
	(void)(n);

	write(STDERR_FILENO, "\n$ ", 3);
}
