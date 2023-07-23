#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 * Description :  finds and prints the largest 
 * prime factor of the number 612852475143
 * Return: Always 0.
 */

int main(void)
{
	long number = 612852475143;
	long maxPrime = -1;
	long i = 3;

	while (number % 2 == 0)
	{
		maxPrime = 2;
		number /= 2;
	}

	for (i = 3; i <= sqrt(number); i += 2)
	{
		 while (number % i == 0)
		 {
			 maxPrime = i;
			 number /= i;
		 }
	}

	if (number > 2)
	{
		maxPrime = number;
	}

	printf("%ld\n", maxPrime);
	return (0);
}
