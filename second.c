#include "main.h"

/**
 * _printf - print the characters according to the format sting.
 * @format: pointer to a set of characters
 * Return: return the string(excluding the null terminator.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int num = va_arg(args, int);

			count += printf("%d", num);
			format += 2;
		}
		else
		{
			putchar(*format);
			count++;
			format++;
		}
	}
	va_end(args);
	return (count);
}
