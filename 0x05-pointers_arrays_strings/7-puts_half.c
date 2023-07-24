#include "main.h"

/**
 * puts_half - function that prints half of a string.
 * @str: string value.
 * Return: void.
 */

void puts_half(char *str)
{
	int length = 0;
	int start_index;

	while (length >= 0)
	{
		if (str[length] == '\0')
		{
			break;
		}
		length++;
	}

	if (length % 2 == 1)
	{
		start_index = length / 2;
	}

	else
	{
		start_index = (length - 1) / 2;
	}
	for (start_index++; start_index < length; start_index++)
	{
		_putchar(str[start_index]);
	}
	_putchar('\n');
}
