#include "main.h"

/**
 * is_separator - Function to check if a character is a separator
 * @c: character
 *
 * Return: 0(false) or 1(true)
 */

int is_separator(char c)
{
	char separators[] = " \t\n,;.!?\"(){}";
	int i;

	for (i = 0; separators[i] != '\0'; i++)
	{
		if (c == separators[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * cap_string - function that capitalizes all words of a string.
 * @str: string.
 *
 * Return: pointer to str.
 */

char *cap_string(char *str)
{
	char *ptr = str;
	int capitalize_next = 1;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z' && capitalize_next)
		{
			*str = *str - ('a' - 'A');
			capitalize_next = 0;
		}
		else if (is_separator(*str))
		{
			capitalize_next = 1;
		}
		else
		{
			capitalize_next = 0;
		}
		str++;
	}
	return (ptr);
}
