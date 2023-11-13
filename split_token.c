#include "shell.h"

/**
 * split_tokens - A fumction that splits input into tokens
 *
 * @str: the input string
 *
 * Return: the array of tokens
 */

char **split_tokens(char *str)
{
	int buffsize, i;
	char **tokens;
	char *token;

	buffsize = BUFF_SIZE;
	i = 0;

	tokens = malloc(buffsize * sizeof(char *));

	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(str, DELIMITER);

	while (token != NULL)
	{
		tokens[i] = _strdup(token);
		i++;
	}
}
