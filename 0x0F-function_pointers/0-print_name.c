#include "function_pointers.h"

/**
 * print_name - prints the name
 * @name: name
 * @f: function
 * Return : nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
