#include "main.h"

/**
 * print_triangle - prints a triangle
 * @s: size of the triangle.
 * Return: void, nothing.
 */
void print_triangle(int s)
{
	int a, b;

	for (a = 0; a < s; a++)
	{
		for (b = 1; b < (s - a); b++)
		{
			_putchar(' ');
		}

		for (b--; b < s; b++)
		{
			_putchar('#');
		}

		if (a < (s - 1))
		{
			_putchar('\n');
		}
	}

	_putchar('\n');
}
