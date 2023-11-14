#include "shell.h"

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 * Return: Always 0 (success)
 */

int main(int argc, char **argv)
{
	char *input = NULL;
	char **commands = NULL;
	int status, line_num, mode;

	status = 1;
	line_num = 1;
	mode = 0;
	(void)argc;

	signal(SIGINT, signal_handler);

	while (status)
	{
		mode = print_prompt();
		input = get_input();

		if (!input)
		{
			perror("Error reading input");
			continue;
		}

		commands = split_tokens(input);

		if (!commands || !*commands || **commands == '\0')
		{
			free(input);
			line_num++;

			continue;
		}

		free(input);
		status = execute_commands(commands, line_num, argv[0]);
	}
}
