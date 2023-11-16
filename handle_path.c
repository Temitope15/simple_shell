#include "shell.h"

/**
 * handle_path - This handles the shell path
 * @args: arguments
 * Return: void
 */

char *handle_path(char **args)
{
	char *path;
	char *command = args[0];
	char filename[MAX_INPUT_LENGTH];
	char *path_duplicate;
	char *token;
	int path_length;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_duplicate = (char *)malloc((_strlen(path) + 1) * sizeof(char));
	if (path_duplicate == NULL)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}

	_strcpy(path_duplicate, path);
	token = strtok(path_duplicate, ":");
	while (token != NULL)
	{
		path_len = _strlen(token);

		_strcpy(filename, token);
		if (filename[path_len - 1] != '/')
		{
			_strcat(filename, "/");
		}
		_strcat(filename, command);

		if (access(filename, F_OK | X_OK) == 0)
		{
			command = filename;
			free(path_duplicate);
			return (command);
		}
		token = strtok(NULL, ":");
	}
	free(path_duplicate);
	return (NULL);
}
