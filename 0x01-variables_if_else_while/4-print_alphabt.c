#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the alphabet except q and e
 *
 * Return: 0 (success)
 */

int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		putchar(c * (c != 'q' && c != 'e'));
	}

	putchar('\n');

	return (0);
}
