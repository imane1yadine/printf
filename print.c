#include "main.h"
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
	va_list args;
	int enami = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == ' '))
		return (-1);
	while (*format != ' ')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					enami += write(1, va_arg(args, int*), 1);
					break;
				case 's':
					enami += printf("%s", va_arg(args, char *));
					break;
				case '%':
					enami += write(1, "%", 1);
					break;
				default:
					enami += write(1, "%", 1);
					enami += write(1, format, 1);
					break;
			}
		}
		else
		{
			enami += write(1, format, 1);
		}
		format++;
	}

	va_end(args);
	return (enami);
}
