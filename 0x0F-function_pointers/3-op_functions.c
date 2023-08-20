#include "3-calc.h"

/**
 * op_add - adds two numbers.
 * @a: number 1.
 * @b: number 2.
 *
 * Return: result.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtract two numbers.
 * @a: number 1.
 * @b: number 2.
 *
 * Return: result.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers.
 * @a: number 1.
 * @b: number 2.
 *
 * Return: result.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two numbers.
 * @a: number 1.
 * @b: number 2.
 *
 * Return: result.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - calculates the modulo of two numbers.
 * @a: number 1.
 * @b: number 2.
 *
 * Return: result.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
