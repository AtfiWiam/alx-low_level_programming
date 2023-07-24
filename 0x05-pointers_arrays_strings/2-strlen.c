#include "main.h"

/**
 * _strlen - function that returns the lenght of a string.
 * @s: string value.
 *
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
