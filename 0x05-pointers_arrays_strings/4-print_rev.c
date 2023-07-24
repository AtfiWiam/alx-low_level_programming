#include "main.h"

/**
 * _strlen - Function to calculate the length of a string
 * @s: string value.
 *
 * Return: length
 */
int _strlen(char *s)
{
	int length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}

	return length;
}

/**
 * print_rev - prints a string, in reverse,
 * @s: string value.
 *
 * Return: void.
 */
void print_rev(char *s)
{
	int length = _strlen(s);
	char *end = s + length - 1;

	while (end >= s)
	{
		_putchar(*end);
		end--;
	}

	_putchar('\n');
}
