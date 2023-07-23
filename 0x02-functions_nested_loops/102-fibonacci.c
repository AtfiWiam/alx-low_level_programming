#include <stdio.h>
/**
 * main - Entry point
 * Description: prints the first 50 Fibonacci numbers
 * Return: 0
 */
int main(void)
{
	int i = 0;
	long int a = 0, b = 1, fib;

	while (i < 50)
	{
		fib = a + b;
		a = b;
		b = fib;
		printf("%lu", fib);

		if (i < 49)
		{
			printf(", ");
		}
		i++;
	}
	printf("\n");
	return (0);
}
