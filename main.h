#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define CUSTOM_BUFF_SIZE 1024

/* Function declarations */
int my_printf(const char *customFormat, ...);
int getCustomFlags(const char *customFormat, int *index);
int getCustomWidth(const char *customFormat, int *index, va_list argsList);
int getCustomPrecision(const char *customFormat, int *index, va_list argsList);
int getCustomSize(const char *customFormat, int *index);
int handleCustomPrint(const char *customFormat, int *index, va_list argsList,
		      char outputBuffer[], int customFlags, int customWidth,
		      int customPrecision, int customSize);
void printOutputBuffer(char outputBuffer[], int *outputBufferIndex);

#endif /* MAIN_H */

