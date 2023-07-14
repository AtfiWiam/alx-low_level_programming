#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the alphabet
 *
 * Return: 0 (success)
 */

int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		putchar(c);
	}

	putchar('\n');

	return (0);
}
