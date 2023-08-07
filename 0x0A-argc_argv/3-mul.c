#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two given numbers.
 * @argc: number of command line argumments.
 * @argv: arguments passed to the program.
 *
 * Return: 0 (Success), 1 if error.
 */

int main(int argc, char *argv[])
{
	int res;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	res = atoi(argv[1]) * atoi(argv[2]);

	printf("%d\n", res);

	return (0);
}
