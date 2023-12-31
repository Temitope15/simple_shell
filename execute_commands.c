#include "shell.h"
#include "buitlin.h"

/**
 * execute_commands - function to execute commands
 * @args: Arguments to execute
 * @line_num: The number of the current command, it shows
 * how many commands have been entered till present
 * @program_name: Executable name
 * Return: 1 or 127 if command not found
 */

int execute_commands(char **args, int line_num, char *program_name)
{
	pid_t pid;
	int i, status;
	char *command;

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			(builtins[i].function(args));
			return (1);
		}
	}

	command = handle_path(args);
	if (command == NULL)
	{
		command = handle_special_path(args);
		if (command == NULL)
		{
			print_error_message(line_num, prog_name, args[0]);
			return (127);
		}
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(command, args, environ) < 0)
		{
			print_error_message(line_num, prog_name, args[0]);
			exit(127);
		}
	}
	else if (pid < 0)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return (1);
}
