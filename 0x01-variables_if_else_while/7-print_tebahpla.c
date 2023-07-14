#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the alphabet backwards
 *
 * Return: 0 (success)
 */

int main(void)
{
	char c;

	for (c = 'z'; c >= 'a'; c--)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}
