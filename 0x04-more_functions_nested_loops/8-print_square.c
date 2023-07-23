#include "main.h"

/**
 * print_square - prints a square,
 * @s: is the size of the square.
 * Return: void.
 */
void print_square(int s)
{
	int a, b;

	for (a = 0; a < s; a++)
	{
		for (b = 0; b < s; b++)
		{
			_putchar('#');
		}

		if (a != s - 1)
		{
			_putchar('\n');
		}
	}

	_putchar('\n');
}

