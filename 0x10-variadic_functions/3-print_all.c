#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format string.
 * @format: A list of types of arguments passed to the function.
 * @...: The list of arguments.
 * Return : Nothing
 */

void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";
	const char valid_types[] = "cifs";
	unsigned int j;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (valid_types[j])
		{
			if (format[i] == valid_types[j])
			{
				printf("%s", separator);
				if (format[i] == 'c')
					printf("%c", va_arg(args, int));
				else if (format[i] == 'i')
					printf("%d", va_arg(args, int));
				else if (format[i] == 'f')
					printf("%f", va_arg(args, double));
				else if (format[i] == 's')
				{
					str = va_arg(args, char *);
					if (!str)
						printf("(nil)");
					else
						printf("%s", str);
				}
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
