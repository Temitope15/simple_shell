#include "shell.h"

/**
 * get_input - a function that gets user input from
 * std input
 * Return: the input gitten from the user as a string
 */

char *get_input(void)
{
	char *input = NULL;
	size_t buffsize;
	ssize_t line_len;

	buffsize = 0;
	line_len = getline(&input, &buffsize, stdin);

	if (line_len < 0)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}

		free(input);
		perror("Error reading input in get_input");
		exit(EXIT_FAILURE);
	}

	if (input[line_len - 1] == '\n')
		input[line_len - 1] = '\0';

	return (input);
}
