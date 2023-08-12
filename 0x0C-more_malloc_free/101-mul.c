#include "main.h"
#include <stdlib.h>

/**
 * _todigit - convert a char to integer.
 * @c: char to convert.
 * Return: integer.
 **/

int _todigit(char c)
{
	unsigned int i;

	if (c <= '9' && c >= '0')
		i = c - '0';
	return (i);
}

/**
 * _isNumber - check if a string is a number.
 * @argv: Pointer to string.
 * Return: success (0).
 **/

int _isNumber(char *argv)
{
	int n;

	for (n = 0; argv[n]; n++)
	{
		if (argv[n] < 48 || argv[n] > 57)
			return (1);
	}
	return (0);
}

/**
 *_calloc - allocate array of size x.
 * @nmemb: number of elements.
 * @size: size of element.
 * Return: pointer to array.
 **/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *arr;
	unsigned int i;

	arr = malloc(size * nmemb);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		arr[i] = '0';

	return (arr);
}

/**
 * _multiply - multiply two arrays.
 * @a1: first array.
 * @len1: length of array a1.
 * @a2: char
 * @a3: array for result.
 * @len3: length of array a3.
 * Return: pointer to result array.
 **/

void *_multiply(char *a1, int len1, char a2, char *a3, int len3)
{
	int mul = 0, i, k;

	k = len3;
	for (i = len1 - 1; i >= 0 ; i--)
	{
		mul += (a1[i] - '0') * (a2 - '0') + (a3[k] - '0');
		a3[k] = (mul % 10) + '0';
		mul /= 10;
		k--;
	}

	while (mul != 0)
	{
		mul += a3[k] - '0';
		a3[k] = (mul % 10) + '0';
		mul /= 10;
		k--;
	}

	return (a3);
}

/**
 * print_arr - prints digits of array.
 * @n: number of elements to print.
 * @arr: array of elements.
 **/

void print_arr(char *arr, int n)
{
	int i = 0;

	while (arr[i] == '0' && (i + 1) < n)
	{
		i++;
	}
	for (; i < n; i++)
	{
		_putchar(arr[i]);
	}
	_putchar('\n');
}

/**
 *main - Entry point
 *print the multiplication of 2 numbers.
 *@argc: array length.
 *@argv: array.
 *Return: 0.
 */

int main(int argc, char *argv[])
{
	int i, c, len1, len2, lres;
	char E[6] = {'E', 'r', 'r', 'o', 'r', '\n'};
	char *ares;

	if (argc != 3 || _isNumber(argv[1]) == 1 || _isNumber(argv[2]) == 1)
	{
		for (i = 0; i < 6; i++)
		{
			_putchar(E[i]);
		}
		exit(98);
	}
	for (len1 = 0; argv[1][len1]; len1++)
		;
	for (len2 = 0; argv[2][len2]; len2++)
		;

	lres = len1 + len2;
	ares = _calloc(lres, sizeof(int));

	if (ares == NULL)
	{
		free(ares);
		return (0);
	}
	for (i = len2 - 1, c = 0; i >= 0; i--)
	{
	ares = _multiply(argv[1], len1, argv[2][i], ares, (lres - 1 - c));
	c++;
	}
	print_arr(ares, lres);
	free(ares);
	exit(EXIT_SUCCESS);
	return (0);
}
