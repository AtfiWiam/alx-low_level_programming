#include <stdio.h>

/**
 * main - print the program name.
 * @argc: number of command line arguments.
 * @argv: arguments passed to the program
 *
 * Return: Always 0 (Success).
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);

	return (0);
}
