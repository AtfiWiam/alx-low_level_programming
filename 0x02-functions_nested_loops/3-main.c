#include <stdio.h>
#include "main.h"

int main(void)
{
	char ch = 'a';

	if (_islower(ch))
	{
		_putchar('1');
	}
	else
	{
		_putchar('0');
	}
	_putchar('\n');
	return (0);
}
