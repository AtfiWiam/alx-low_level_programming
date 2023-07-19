#include <stdio.h>
#include "main.h"

int main(void)
{
	char ch = 'A';

	if (_isalpha(ch) || _isalpha(ch + 32))
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
