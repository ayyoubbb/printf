#include "main.h"

/**
 * _printf -  produces output according to format
 * @format: pointer to strings
 *
 * Return: return int
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%')) {
			format++;

			if (*format == 'c') {
				char c = (char)va_arg(args, int);
				count += write(1, &c, 1);
			} else if (*format == 's') {
				count += write(1, va_arg(args, char *), 1);
			} else if (*format == '%') {
				count += write(1, "%", 1);
			} else {
				count += write(1, "%", 1);
				count += write(1, &(*format), 1);
			}
		} else {
			count += write(1, &(*format), 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
