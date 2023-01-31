#ifndef __UART_H__
#define __UART_H__

#include "chip.h"

void initUART1(void);
void _myputchar(const unsigned int ch);
void _myputs(const char *ptr);
int _mygetchar(void);
char *convert(int num, int base);
void _myprintf(char* format,...);

#endif // __UART_H__

