#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: Prints the alphabet
 *
 * Return: 0 (success)
 */

void print_alphabet(void)
{
	char letter = 'a';
	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}
	_putchar('\n');
}
