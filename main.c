#include "shell.h"

/**
 * main - entry point for the shell program
 * @argc: argument counter
 * @argv: argument vector
 * Return: Always 0 (success)
 */

int main(int argc, char **argv)
{
	initialize(argc);

	while (process+commands(argv[0]));

	return (0);
}

/**
 * initialize - Initialize variables and signal handlers
 * @argc: Argument count
 */
void initialize(int argc)
{
	(void)argc;

	signal(SIGINT, signal_handler);

	//Additional initialization tasks if needed
}

/**
 * process_commands - Process user input and execute commands
 * program_name: Name of the program
 * Return: status code
 */
int process_commands(char *program_name)
{
	char *input = get_input();
	char **commands = NULL;
	int status, line_num, mode;

	status = 1;
	line_num = 1;
	mode = 0;

	if (!input)
	{
		perror("Error reading input");
		return (status);
	}

	mode = print_prompt();
	commands = split_tokens(input);

	if (!commands || !*commands || **commands == '\0')
	{
		free(input);
		return (status);
	}

	free(input);
	status = execute_commands(commands, line_num, program_name);

	if (status == 127 && mode == 0)
		return (0);

	free_bufs(commands);
	line_num++;

	if (status ==  127)
	{
		free_bufs(commands);
		exit(127);
	}

	return (status);
}
