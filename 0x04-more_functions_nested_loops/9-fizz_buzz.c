#include <stdio.h>

/**
 * main - Entry point
 * Description : Print fizz for multiple of 3
 * buzz for multiple of 5
 * Fizzbuzz for multiple of 3 and 5
 * Return: 0
 */
int main(void)
{
	int a = 0;

	for (a = 1; a <= 100; a++)
	{
		if ((a % 3 == 0) && (a % 5 == 0))
		{
			printf(" FizzBuzz");
		}
		else if (a % 3 == 0)
		{
			printf(" Fizz");
		}
		else if (a % 5 == 0)
		{
			printf(" Buzz");
		}
		else
		{
			printf(" %d", a);
		}
	}

	printf("\n");

	return (0);

}

