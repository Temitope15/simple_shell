#include "shell.h"

/**
 * cd_error_message - Prints an error message to stderr
 * @message: Error message.
 */

void cd_error_message(const char *message)
{
	size_t message_len;

	message_len = _strlen(message);
	write(STDERR_FILENO, message, message_len);
	write(STDERR_FILENO, "\n", 1);
}

/**
 * command_error - Generates an error for oa wrong command
 * @line_num: the line number where the is error
 * @p_name: Program name
 * @cmd: wrong command
 *
 * Return:  A pointer to the generated error message or NULL
 * if memory allocation fails.
 */
char *command_error(int line_num, char *p_name, char *cmd)
{
	char *error_msg, num_str[12];
	int len;

	if (_itoa(num_str, line_num) == NULL)
		return (NULL);

	len = _strlen(p_name) + _strlen(cmd) + _strlen(num_str) + 18;
	
	error_msg = malloc(sizeof(char) * (len + 1));
	if (error_msg == NULL)
		return (NULL);

	_strcpy(error_msg, p_name);
	_strcat(error_msg, ": ");
	_strcat(error_msg, num_str);
	_strcat(error_msg, ": ");
	_strcat(error_msg, cmd);
	_strcat(error_msg, ": not found\n");

	return (error_msg);
}

/**
 * print_error_message - prints an error message to stderr
 * @line_num: The line number where the error occurred
 * @p_name: The program name
 * @cmd: The command that caused the error
 */

void print_error_message(int line_num, char *p_name, char *cmd)
{
	char *error;
	int length;

	error = command_error(line_num, p_name, cmd);
	if (error)
	{
		length = _strlen(error);
		write(STDERR_FILENO, error, length);
		free(error);
	}
}
