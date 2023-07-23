#include "main.h"

/**
 * print_diagonal - check for a digit
 * @n : number of \ to be printed
 * Return:void
 */
void print_diagonal(int n)
{
	int i = 1;
	int j = 1;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	while (i <= n)
	{
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
