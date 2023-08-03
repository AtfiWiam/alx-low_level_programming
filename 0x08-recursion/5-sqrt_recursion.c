#include "main.h"

/**
 * find_sqrt - find square root of a number.
 * @n: integer value.
 * @guess: integer value.
 * Return: square root or -1.
 */

int find_sqrt(int n, int guess)
{
	if (guess * guess == n)
	{
		return (guess);
	}
	else if (guess * guess > n)
	{
		return (-1);
	}
	else
	{
		return (find_sqrt(n, guess + 1));
	}
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: input number.
 * Return: natural square root.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_sqrt(n, 0));
}
