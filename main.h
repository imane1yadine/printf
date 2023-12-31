#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _putchar(char character);
int printf_char(va_list args, int printed);
int printf_string(va_list args, int printed);
int printf_integer(va_list args, int printed);
int selector(const char *format, va_list args, int printed);
int printf_binary(unsigned int num, int printed);
int _printf(const char *format, ...);
int _x(unsigned int num, int printed, int uppercase);
int printf_octal(unsigned int num, int printed);
int printf_unsigned(unsigned int num, int printed);
int printf_reverse(va_list args, int printed);
int printf_pointer(va_list args, int printed);

#endif
