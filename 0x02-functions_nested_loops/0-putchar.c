#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: Prints _putchar
 *
 * Return: 0 (success)
 */

int main(void)
{
	char str[] = "_putchar\n";
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (0);
}
