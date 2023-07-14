#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints if a number is positive, negative or null
 *
 * Return: 0 (success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n==0)
	{
		printf("&n is zero\n");
	}
	else if (n>0)
	{
		printf("&n is positive\n");
	}
	else
	{
		printf("&n is negative\n");
	}
	return (0);
}
