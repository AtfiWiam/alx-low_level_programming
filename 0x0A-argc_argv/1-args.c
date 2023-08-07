#include <stdio.h>

/**
 * main - print the number of argument passed into it.
 * @argc: number of command line arguments.
 * @argv: arguments passed to the program
 *
 * Return: 0 (Success).
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);

	return (0);
}
