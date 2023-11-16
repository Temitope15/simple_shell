#include "shell.h"
/**
 * _strlen - String length
 *
 * @s: String
 *
 * Description: How to get string length
 *
 * Return: String length
 */
int _strlen(const char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
 * _strncpy - Copies a string at maximum bytes
 *
 * @desti: Destination
 *
 * @src: Source
 *
 * @b: maximum number of bytes to copy
 *
 * Description: String copying
 *
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *desti, const char *src, int b)
{
	int j;

	for (j = 0; j < b && src[j] != '\0'; j++)
		desti[j] = src[j];

	for ( ; j < b; j++)
		desti[j] = '\0';

	return (desti);
}
/**
 * _strcmp - Compares two strings
 *
 * @fs1: First string
 *
 * @ss2: Second string
 *
 * Description : Comparing strings
 *
 * Return: integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *fs1, char *ss2)
{
	int j;

	for (j = 0; fs1[j] != '\0' && ss2[j] != '\0'; j++)
	{
		if (fs1[j] != ss2[j])
			return (fs1[j] - ss2[j]);
	}

	if (fs1[j] != '\0' || ss2[j] != '\0')
		return (fs1[j] - ss2[j]);

	return (0);

}

/**
 * _strcpy - Copies a string
 *
 * @dest: Destination
 *
 * @src: source string
 *
 * Description: A function that copies a string
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
