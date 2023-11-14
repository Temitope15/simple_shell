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
