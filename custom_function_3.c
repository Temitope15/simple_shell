#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 * Description: comparing strings
 *
 * Return: integer less than, equal to or greater than zero
 * if s1 is found.
 */

int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] != '\0' && s2[j] != '\0'; j++)
	{
		if (s1[j] != s2[j])
			return (s1[j] - s2[j]);
	}

	if (s1[j] != '\0' || s2[j] != '\0')
		return (s1[j] - s2[j]);

	return (0);
}

/**
 * _strchr - locate character in string
 * @str: pointer to the string to be searched
 * @ch: character to be located
 *
 * Return: pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found
 */
char *_strchr(const char *str, int ch)
{
	while (*str != '\0' && *str != ch)
		++str;
	if (*str == ch)
		return ((char *)str);
	else
		return (NULL);
}

/**
 * _strcat - concatenates two strings from src to dest
 * @dest: destination string
 * @src: source string
 * Description: This function concatenates strings
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, const char *src)
{
	int a, b;

	a = 0;
	while (dest[a] != '\0')
		a++;
	b = 0;
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strncmp - Compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to compare
 *
 * Description: A function that compares strings
 *
 * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
