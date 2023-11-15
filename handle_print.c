#include "main.h"

/**
 * handle_unknown_format - Handle unknown format character
 * @fmt: Formatted string to print the arguments
 * @ind: Pointer to the current index in the format string
 * @width: Width
 *
 * Return: 1 if handled, 0 otherwise
 */
int handle_unknown_format(const char *fmt, int *ind, int width)
{
	if (width)
	{
		(*ind)--;
		while (fmt[*ind] != ' ' && fmt[*ind] != '%' && fmt[*ind] != '\0')
			(*ind)++;
		if (fmt[*ind] == ' ')
			(*ind)--;
		return (1);
	}
	return (0);
}

/**
 * handle_known_format - Handle known format character
 * @list: List of arguments to be printed
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * @fn: Function pointer to the appropriate print function
 *
 * Return: Number of characters printed
 */
int handle_known_format(va_list list, char buffer[], int flags,
		int width, int precision, int size,
		int (*fn)(va_list, char[], int, int, int, int))
{
	return (fn(list, buffer, flags, width, precision, size));
}

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string to print the arguments
 * @ind: Index
 * @list: List of arguments to be printed
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int printed_chars = -1;
	fmt_t fmt_types[] =
	{
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	char current_fmt = fmt[*ind];
	int format_index;

	for (format_index = 0; fmt_types[format_index].fmt != '\0'; format_index++)
	{
		if (current_fmt == fmt_types[format_index].fmt)
		{
            return (handle_known_format(list, buffer, flags, width, precision, size,
			    fmt_types[format_index].fn));
		}
	}

	if (fmt_types[format_index].fmt == '\0')
	{
		if (current_fmt != '\0')
		{
			printed_chars += write(1, "%%", 1);
			printed_chars += (current_fmt == ' ' ? write(1, " ", 1) : 0);
			if (width)
			{
				handle_unknown_format(fmt, ind, width);
				return (1);
			}
			printed_chars += write(1, &current_fmt, 1);
		}
		else
		{
			return (-1);
		}
	}

	return (printed_chars);
}
