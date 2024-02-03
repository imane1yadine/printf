#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: format string.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int enami = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format) 
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
					{
						char *str = va_arg(args, char *);
						if (str == NULL) str = "(null)";
						while (*str)
						{
							enami += putchar(*str++);
						}
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						char numStr[12]; /* Enough for 32-bit int, including sign and null terminator */
						sprintf(numStr, "%d", num);
						char *p;
						p = /* some value */;
						p = numStr;
						while (*p)
						{
							enami += putchar(*p++);
						}
						break;
					}
				case '%':
					enami += putchar('%');
					break;
				default:
					/* Print the percent and the unrecognized character */
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
