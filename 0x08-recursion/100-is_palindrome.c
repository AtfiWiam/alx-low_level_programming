#include "main.h"

/**
 * is_equal - compares characters at the start
 * and end of the string, moving towards the center.
 * @s: string value.
 * @start: start of string
 * @end: end of string
 *
 * Return: 0 if not equal, 1 if equal
 */

int is_equal(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (is_equal(s, start + 1, end - 1));
}


/**
 * _strlen - calculates the length of the string using
 * @s: string value.
 *
 * Return: lenght
 */

int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

/**
 * is_palindrome - checks if a string is a palindrome or not
 * @s: string value.
 *
 * Return: returns 1 if a palindrome and 0 if not.
 */

int is_palindrome(char *s)
{
	int length = _strlen(s);

	return (is_equal(s, 0, length - 1));

}
