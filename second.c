#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);
	for (ptr = format; *ptr != '\0'; ++ptr)
	{
		if (*ptr == '%' && (*(ptr + 1) == 'd' || *(ptr + 1) == 'i'))
		{
			int num = va_arg(args, int);

			count += printf("%d", num);
			++ptr;
		}
		else
		{
			putchar(*ptr);
			++count;
		}
	}
	va_end(args);
	return (count);
}
