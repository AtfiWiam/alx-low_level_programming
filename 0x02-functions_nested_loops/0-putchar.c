#include <stdio.h>


/**
 * main - Entry point of the program
 *
 * Description: Prints _putchar
 *
 * Return: 0 (success)
 */

int _putchar(char c)
{
	return putchar(c);
}

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
