#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program,
 * 101-crackme.
 * Return: Always 0 (Success).
 */

int main(void)
{
	int random_password = 0, a = 0;

	time_t t;

	srand((unsigned int) time(&t));

	while (a < 2772)
	{
		random_password = rand() % 128;
		if ((a + random_password) > 2772)
		{
			break;
		}
		a = a + random_password;
		printf("%c", random_password);
	}
	printf("%c\n", (2772 - a));

	return (0);
}
