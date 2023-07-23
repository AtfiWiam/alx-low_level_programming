#include "main.h"

/**
 * print_diagonal - function that draws a diagonal line,
 * @n: is the number of times the character \ is printed
 * Return: void,
 */
void print_diagonal(int n)
{
	int a, b;

	for (a = 0; a < n; a++)
	{
		for (b = 0; b < a; b++)
		{
			_putchar(' ');
		}

		_putchar(92);

		if (a < (n - 1))
		{
			_putchar('\n');
		}
	}

	_putchar('\n');
}

