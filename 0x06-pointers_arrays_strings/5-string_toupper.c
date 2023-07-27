#include "main.h"

/**
 * string_toupper - function that changes all lowercase letters
 * of a string to uppercase.
 * @str: string
 *
 * Return: pointer to str.
 */

char *string_toupper(char *str)
{
	char *ptr = str;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
		{
			*str = *str - ('a' - 'A');
		}
		str++;
	}
	return (ptr);
}
