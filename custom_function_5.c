#include "shell.h"

/**
 * _strstr - Locates the first occurrence of the substring needle
 *             in the string haystack.
 * @haystack: The string to search in.
 * @needle: The substring to search for.
 *
 * Return: If needle is an empty string, haystack is returned;
 *         if needle occurs nowhere in haystack, NULL is returned;
 *         otherwise, a pointer to the first character of the first
 *         occurrence of needle in haystack is returned.
 */
const char *_strstr(const char *haystack, const char *needle)
{
	const char *h;
	const char *n;

	if (needle == NULL || *needle == '\0')
		return (haystack);

	if (haystack == NULL)
		return (NULL);

	while (*haystack)
	{
		h = haystack;
		n = needle;

		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}

/**
 * reverse_string - Reverses a string.
 * @str: The string to be reversed.
 * @length: The length of the string.
 */
void reverse_string(char *str, int length)
{
	int start, end;
	char temp;

	start = 0;
	end = length - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * _itoa - Converts an integer to a string.
 * @str: The buffer to store the converted string.
 * @num: The integer to be converted.
 *
 * Return: The length of the converted string.
 */
int _itoa(char *str, int num)
{
	int is_negative, i, digit;

	if (num == 0)
	{
		str[0] = '0';
		return (1);
	}

	is_negative = 0;
	i = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num != 0)
	{
		digit = num % 10;
		str[i++] = digit + '0';
		num /= 10;
	}

	if (is_negative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	reverse_string(str, i);

	return (i);
}

/**
 * _st - copies the contents of src1, src2 and src3 to dest
 * @dest: destination string
 * @src1: source string 1
 * @src2: source string 2
 * @src3: source string 3
 *
 * Description: Copying multiple content
 *
 * Return: void
 */
void _st(char *dest, const char *src1, const char *src2, const char *src3)
{
	while (*src1)
	{
		*dest++ = *src1++;
	}

	while (*src2)
	{
		*dest++ = *src2++;
	}

	while (*src3)
	{
		*dest++ = *src3++;
	}

	*dest = '\0';
}
