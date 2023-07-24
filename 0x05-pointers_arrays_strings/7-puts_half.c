#include "main.h"

/**
 * _strlen - function to calculate the length of a string
 * @s: string value.
 * Return: length.
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

/**
 * puts_half - function that prints half of a string.
 * @str: string value.
 * Return: void.
 */

void puts_half(char *str)
{
	int length = _strlen(str);
	int start_index;
	int i;

	if (length % 2 == 1)
	{
		start_index = length / 2;
	}

	else
	{
		start_index = (length - 1) / 2;
	}
	for (i = start_index; i < length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
