#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int enami = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (*format != ' ')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					enami += putchar(va_arg(args, int));
					break;
				case 's':
					enami += printf("%s", va_arg(args, char *));
					break;
				case '%':
					enami += putchar('%');
					break;
				default:
					enami += putchar('%');
					enami += putchar(*format);
					break;
			}
		}
		else
		{
			enami += putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (enami);
}
