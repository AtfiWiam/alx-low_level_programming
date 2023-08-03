#include "main.h"

/**
 * is_equal - compares if characters are equals
 * @c1: character from first string
 * @c2: character from second string.
 *
 * Return: 1 if c1 and c2 are identical, 0 if they are not identical.
 */

int is_equal(char c1, char c2)
{
	return ((c1 == c2) || (c2 == '*'));
}

/**
 * wildcmp - compares two strings.
 * @s1: first string value.
 * @s2: second string value. can contains a * as a special character.
 *
 * Return: 1 if s1 and s2 are identical, 0 if they are not identical.
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (*s1 == '\0')
		{
			return (wildcmp(s1, s2 + 1));
		}
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	else if (*s1 == '\0' || *s2 == '\0')
		return (*s1 == *s2);
	else if (is_equal(*s1, *s2))
		return (wildcmp(s1 + 1, s2 + 1));
	else
		return (0);
}
