#include "shell.h"

/**
 * _realloc - realloc function to reallocate new block
 * of memory
 *
 * @ptr: pointer to the old block of memory
 * @new_size: size of the new block of memory
 *
 * Return: pointer to the new block of memory
 */

void *_realloc(void *ptr, unsigned int new_size)
{
	void *new_ptr;
	size_t old_size = ptr ? sizeof(*((char *) ptr)) * new_size : 0;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		_memcpy(new_ptr, ptr, old_size < new_size ? old_size : new_size);
		free(ptr);
	}

	return (new_ptr);
}


/**
 * _strdup - Duplicates a string
 *
 * @str: The string to be duplicated
 *
 * Return: A pointer to the newly allocated duplicated string.\,
 * or NULL if memory allocation fails or if str is NULL
 */

char *_strdup(const char *str)
{
	size_t len;
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	new_str = (char *) malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
	{
		return (NULL);
	}

	_strcpy(new_str, str);
	return (new_str);
}

/**
 * _strchr - locates character in string
 * @str: pointer to the string
 * @ch: character 
 * Return: pointer to the first occurrence of ch or NULL if not found
 */
char *_strchr(const char *str, int ch)
{
	while (*str != '\0' && str, int ch)
		++str;
	if (*str == ch)
		return ((char *)str);
	else
		return (NULL);
}

/**
 * _setenv - add or modify an environment variable
 * @name: the name of the environment
 * @value: the value to set the environment to
 * @overwrite: a flag indicating whether to overwrite
 *
 * Return: 0 0n success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t i, max_environ =  100;
	int namelen = _strlen(name), valuelen = _strlen(value);
	size_t varlen = namelen + valuelen + 2;
	char *new_var = malloc(varlen);

	if (!name || !*name || _strchr(name, '=') || !value || !environ)
		return (-1);

	if (!new_var)
		return (-1);

	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, namelen) == 0 && environ[i][namelen] == '=')
		{
			if (overwrite)
				_strncpy(environ[i], new_var, varlen);
			free(new_var);

			return (0);
		}
	}

	if (i >= max_environ)
	{
		free(new_var);
		return (-1);
	}

	environ[i] = new_var;
	environ[i + 1] = NULL;

	return (0);
}
