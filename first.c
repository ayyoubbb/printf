#include "main.h"

/**
 *  * _printf - Our custom printf function
 *   * @format: The format string
 *    *
 *     * Return: Number of characters printed (excluding null byte)
 *      */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0; 
char *str;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str)
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
			print_regular_character(*format, &count);
		}

		    
		format++;
	}

	va_end(args);

	return count;
}

/**
 *  * print_regular_character - Prints a regular character and increments the count
 *   * @c: The character to be printed
 *    * @count: Pointer to the count of characters printed
 *     */

void print_regular_character(char c, int *count)
{
	putchar(c);
	(*count)++;
}
