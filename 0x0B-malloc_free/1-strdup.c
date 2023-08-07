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
	size_t length = 0;
	size_t i = 0;
	char *duplicate = (char *)malloc((length + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);
	while (str[length] != '\0')
		length++;
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= length; ++i)
		duplicate[i] = str[i];
	return (duplicate);
}
