#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char buffer[BUFF_SIZE];
	int buff_ind = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			buffer[buff_ind++] = *format;
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			format++;
			printed_chars += handle_format(&format, args, buffer);
		}

		format++;
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * handle_format - Handles the format specifier and prints accordingly
 * @format: Pointer to the format string
 * @args: Variable arguments list
 * @buffer: Buffer to store characters before printing
 * Return: Number of characters printed
 */
int handle_format(const char **format, va_list args, char buffer[])
{
	int flags, width, precision, size, printed = 0;

	flags = get_flags(*format);
	width = get_width(*format, args);
	precision = get_precision(*format, args);
	size = get_size(*format);

	printed = handle_print(*format, args, buffer, flags, width, precision, size);

	return (printed);
}
