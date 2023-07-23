#include "main.h"

/**
 * print_diagonal - draws a diagonal line
 * @n : number of \ to be printed
 * Return:void
 */

void print_diagonal(int n)
{
	int i = 1;
	int j;

	if (n <= 0)
	{
		_putchar('\n');
	}
	while (i <= n)
	{
		j = 1;

		while (j < i)
		{
			 _putchar(' ');
			 j++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
	}
}
