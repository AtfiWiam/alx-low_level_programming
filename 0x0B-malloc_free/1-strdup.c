#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory.
 *
 * @str: string.
 *
 * Return: pointer of a new string, NULL if str = NULL.
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int a, b;

	if (str == NULL)
	{
		return (NULL);
	}

	for (a = 0; str[a] != '\0'; a++)
	{
		;
	}

	duplicate = (char *)malloc(sizeof(char) * (a + 1));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (b = 0; b <= a; b++)
	{
		duplicate[b] = str[b];
	}

	return (duplicate);
}
