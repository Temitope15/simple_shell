#include "shell.h"

/**
 * _getenv - It returns the value environment variable
 *
 * @name: Environment name
 *
 * Description: Environmental variable
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *name)
{
	int name_len = _strlen(name);
	char *var;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			var = *env + name_len + 1;
			return (var);
		}
	}
	return (NULL);
}

/**
 * _atoi - Converts a string to integer
 * @s: string to be converted
 *
 * Description: String converter
 *
 * Return: Converted string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}

/**
 * _unsetenv - remove an environment variable
 * @name: the name of the environment variable to remove
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int i, j, name_len;

	if (!name || !*name || _strchr(name, '=') || !environ)
		return (0);
	name_len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 &&
				environ[i][name_len] == '=')
		{
			for (j = i; environ[j + 1] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
			environ[j] = NULL;
			return (0);
		}
	}
	return (0);
}

/**
 * _strtok - A function that tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter to use for tokenization
 *
 * Return: A pointer to the next token or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_str;
	char *start, *end;

	if (str != NULL)
	{
		last_str = str;
	}

	if (last_str == NULL)
	{
		return (NULL);
	}

	start = last_str;
	while (*start && _strchr(delim, *start))
	{
		start++;
	}

	if (*start == '\0')
	{
		last_str = NULL;
		return (NULL);
	}

	end = start + 1;
	while (*end && !_strchr(delim, *end))
	{
		end++;
	}

	*end = '\0';
	last_str = end + 1;
	return (start);
}
