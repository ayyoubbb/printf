#include "main.h"

void printOutputBuffer(char outputBuffer[], int *outputBufferIndex);

/**
 *  * my_printf - Custom printf function
 *   * @customFormat: Custom format.
 *    * Return: Number of characters printed.
 *     */
int my_printf(const char *customFormat, ...)
{
	int i, printedChars = 0, printed = 0;
	int customFlags, customWidth, customPrecision, customSize, outputBufferIndex = 0;
	va_list argsList;
	char outputBuffer[CUSTOM_BUFF_SIZE];
	if (customFormat == NULL)
		return (-1);
	va_start(argsList, customFormat);
	for (i = 0; customFormat && customFormat[i] != '\0'; i++)
	{
		if (customFormat[i] != '%')
		{
			outputBuffer[outputBufferIndex++] = customFormat[i];
			if (outputBufferIndex == CUSTOM_BUFF_SIZE)
				printOutputBuffer(outputBuffer, &outputBufferIndex);
			printedChars++;
		}
		else
		{
			printOutputBuffer(outputBuffer, &outputBufferIndex);
			customFlags = getCustomFlags(customFormat, &i);
			customWidth = getCustomWidth(customFormat, &i, argsList);
			customPrecision = getCustomPrecision(customFormat, &i, argsList);
			customSize = getCustomSize(customFormat, &i);
			++i;
			printed = handleCustomPrint(customFormat, &i, argsList, outputBuffer,
					customFlags, customWidth, customPrecision,customSize);
			if (printed == -1)
				return (-1);
			printedChars += printed;
		}
	}
	printOutputBuffer(outputBuffer, &outputBufferIndex);

	va_end(argsList);
	return (printedChars);
}
/**
 *  * printOutputBuffer - Prints the contents of the output buffer if it exists
 *   * @outputBuffer: Array of characters
 *    * @outputBufferIndex: Index at which to add the next character, represents the length.
 *     */
void printOutputBuffer(char outputBuffer[], int *outputBufferIndex)
{
	if (*outputBufferIndex > 0)
		write(1, &outputBuffer[0], *outputBufferIndex);

	*outputBufferIndex = 0;
}

