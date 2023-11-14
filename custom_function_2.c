#include "shell.h"

/**
 * _strcpy - copies a string
 *
 * @dest: DEstination file
 * @src: source file
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _memcpy - a function that copies memory area
 *
 * @dest: memory where it is stored
 * @src: memory where it is copied
 * @n: number of bytes
 *
 * Return: copied memory with n bytes changed
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cdest = dest;
	const char *csrc = src;
	size_t i;

	for (i = 0; i < n; i++)
	{
		cdest[i] = csrc[i];
	}

	return (dest);
}

/**
 * _strlen - gets the length of a string
 *
 * @s: String
 *
 * Return: Length of the string
 */

size_t _strlen(const char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}
