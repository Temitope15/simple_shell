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
	char **cmd = NULL;
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
		commands = split_tokens(input);

		if (!cmd || !*cmd || **cmd == '\0')
		{
			free(input);
			line_num++;

			continue;
		}
		free(input);
		status = execute_commands(cmd, line_num, argv[0]);
	}
}
