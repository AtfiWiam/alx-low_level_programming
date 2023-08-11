#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * multiply - multiply two positive numbers.
 * @argv: command line arguments.
 *
 * Return: 0 always success.
 */

int multiply(char *num1, char *num2)
{
	int len1, len2, result_len, *result;
	int i, j, prod, sum;
	int leading_zero = 0;

	len1 = strlen(num1);
	len2 = strlen(num2);
	result_len = len1 + len2;
	result = (int *)calloc(result_len, sizeof(int));

	if (result == NULL)
		exit (1);
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0');
			sum = prod + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	while (leading_zero < result_len && result[leading_zero] == 0)
		leading_zero++;
	if (leading_zero == result_len)
		printf("0\n");
	else
	{
		for (i = leading_zero; i < result_len; i++)
			printf("%d", result[i]);
	}
	printf("\n");
	free(result);
	return (0);
}
/**
 * main - Entry point.
 * @argc: number of arguments.
 * @argv: command line arguments.
 *
 * Return: 0 - success or error.
 */
int main(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		fprintf(stderr, "Error\n");
		return (98);
	}
	for (i = 1; i <= 2; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (!isdigit(argv[i][j]))
			{
				fprintf(stderr, "Error\n");
				return (98);
			}
		}
	}
	multiply(argv[1], argv[2]);
	return (0);
}
