#include "main.h"
#include <stdio.h>

/**
 * infinite_add - adds two numbers
 * @n1: number one.
 * @n2: number two.
 * @r: buffer that the function will use to store the result.
 * @size_r: buffer size:
 * Return: result
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int a = 0, b = 0, sum = 0;
	int o, g, r1, r2;

	while (*(n1 + a) != '\0')
		a++;
	while (*(n2 + b) != '\0')
		b++;
	if (a >= b)
		g = a;
	else
		g = b;
	if (size_r <= g + 1)
		return (0);
	r[g + 1] = '\0';
	a--, b--, size_r--;
	r1 = *(n1 + a) - 48, r2 = *(n2 + b) - 48;
	while (g >= 0)
	{
		o = r1 + r2 + sum;
		if (o >= 10)
			sum = o / 10;
		else
			sum = 0;
		if (o > 0)
		*(r + g) = (o % 10) + 48;
		else
			*(r + g) = '0';
		if (a > 0)
			a--, r1 = *(n1 + a) - 48;
		else
			r1 = 0;
		if (b > 0)
			b--, r2 = *(n2 + b) - 48;
		else
			r2 = 0;
		g--, size_r--;
	}
	if (*(r) == '0')
		return (r + 1);
	else
		return (r);
}

