#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int curr_i = *i + 1;
	int flags = 0;

	while (format[curr_i] && strchr("-+0# ", format[curr_i]))
	{
		switch (format[curr_i])
		{
			case '-':
				flags |= F_MINUS;
				break;
			case '+':
				flags |= F_PLUS;
				break;
			case '0':
				flags |= F_ZERO;
				break;
			case '#':
				flags |= F_HASH;
				break;
			case ' ':
				flags |= F_SPACE;
				break;
		}
		curr_i++;
	}

	*i = curr_i - 1;

	return (flags);
}

