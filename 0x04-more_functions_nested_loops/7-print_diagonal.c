#include "main.h"

/**
 * print_diagonal - check for a digit
 * @n : number of \\ to be printed
 * Return:void
 */

void print_diagonal(int n)
{
	int i = 0, b;

	while (i < n && n > 0)
	{
		b = 0;
		while (b < i)
		{
			_putchar(' ');
			b++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
		if (i == 0)
		{
		_putchar('\n');
		}
	}
	_putchar('\n');
}
