#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _iszero - checks if any number is zero
 * @argv: command line arguments.
 *
 * Return: nothing.
 */
void _iszero(char *argv[])
{
	int i, n1 = 1, n2 = 1;

	for (i = 0; argv[1][i]; i++)
		if (argv[1][i] != '0')
		{
			n1 = 0;
			break;
		}

	for (i = 0; argv[2][i]; i++)
		if (argv[2][i] != '0')
		{
			n2 = 0;
			break;
		}

	if (n1 == 1 || n2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * _inarray - initialize a new array to zero.
 * @arr: array of char.
 * @len: length of the array
 *
 * Return: pointer to the array.
 */
char *_inarray(char *arr, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
		arr[i] = '0';
	arr[len] = '\0';
	return (arr);
}

/**
 * _check - check the length of the number and if it is in base 10.
 * @argv: command line arguments.
 * @r: row of the array.
 *
 * Return: length of the number.
 */
int _check(char *argv[], int r)
{
	int len;

	for (len = 0; argv[r][len]; len++)
		if (!isdigit(argv[r][len]))
		{
			printf("Error\n");
			exit(98);
		}
	return (len);
}

/**
 * main - Entry point.
 * program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: command line arguments.
 *
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int len1, len2, lenout, sum, suml, i, j, k, ca;
	char *nout;

	if (argc != 3)
		printf("Error\n"), exit(98);
	len1 = _check(argv, 1), len2 = _check(argv, 2);
	_iszero(argv), lenout = len1 + len2, nout = malloc(lenout + 1);
	if (nout == NULL)
		printf("Error\n"), exit(98);
	nout = _inarray(nout, lenout);
	k = lenout - 1, i = len1 - 1, j = len2 - 1, ca = suml = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (suml > 0)
			{
				sum = (nout[k] - '0') + suml;
				if (sum > 9)
					nout[k - 1] = (sum / 10) + '0';
				nout[k] = (sum % 10) + '0';
			}
			i = len1 - 1, j--, suml = 0, ca++, k = lenout - (1 + ca);
		}
		if (j < 0)
		{
			if (nout[0] != '0')
				break;
			lenout--;
			free(nout), nout = malloc(lenout + 1), nout = _inarray(nout, lenout);
			k = lenout - 1, i = len1 - 1, j = len2 - 1, ca = suml = 0;
		}
		if (j >= 0)
		{
			sum = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (nout[k] - '0') + suml;
			suml = sum / 10, nout[k] = (sum % 10) + '0';
		}
	}
	printf("%s\n", nout);
	return (0);
}

