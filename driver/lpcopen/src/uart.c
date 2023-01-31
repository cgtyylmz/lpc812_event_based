#include "uart.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int len = 0;

void initUART1()
{
	Chip_UART_Init(LPC_USART1);
	Chip_UART_ConfigData(LPC_USART1, UART_CFG_DATALEN_8 | UART_CFG_PARITY_NONE | UART_CFG_STOPLEN_1);
	Chip_Clock_SetUSARTNBaseClockRate((115200 * 16), true);
	Chip_UART_SetBaud(LPC_USART1, 115200);
	Chip_UART_Enable(LPC_USART1);
	Chip_UART_TXEnable(LPC_USART1);
}

void _myputchar(const unsigned int ch)
{
	while( !(Chip_UART_GetStatus(LPC_USART1) & UART_STAT_TXRDY) );		/*!< Transmitter ready for data */
	Chip_UART_SendByte(LPC_USART1, ch);
}
void _myputs(const char *ptr)
{
	//Chip_UART_SendRB(UART0_DEBUG_ADDR, &txRingBuff, (const uint8_t *) &ptr, strlen(ptr));
	Chip_UART_SendBlocking(LPC_USART1, (unsigned char *)ptr, sizeof(ptr));
}
//-------------------------------------
int _mygetchar(void)
{
	unsigned int ch;
	Chip_UART_ReadBlocking(LPC_USART1, &ch, 1);
	return ch;
}
//-----------------------------------
char *convert(int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	len = 0;
	ptr = &buffer[49];
	*ptr = '\0';

	do{
		*--ptr = Representation[num%base];
		num /= base;
		len++;
	}while(num != 0);

	return(ptr);
}
//--------------------------------------

void _myprintf(char* format,...)
{

	int i;
	char *s;
	char buff[10];

	//Module 1: Initializing Myprintf's arguments
	va_list arg;
	va_start(arg, format);

	for(; (*format != '\0') ; format++){
		while( *format != '%' ){
			_myputchar(*format);
			format++;
			if(*format == '\0')
				goto endofProcess;
		}

		format++;

		//Module 2: Fetching and executing arguments
		switch(*format){
			case 'c' : i = va_arg(arg,int);				//Fetch char argument
				_myputchar(i);
				break;

			case 'd' : i = va_arg(arg,int); 			//Fetch Decimal/Integer argument
				if(i<0)
				{
					i = -i;
					_myputchar('-');
				}
				itoa(i, buff, 10);
				_myputs(buff);
				break;

			case 'o': i = va_arg(arg,unsigned int); 	//Fetch Octal representation
				_myputchar('o');_myputchar('x');
				_myputs(convert(i,8));
				break;

			case 's': s = va_arg(arg,char *); 			//Fetch string
				_myputs(s);
				break;

			case 'x': i = va_arg(arg,unsigned int); 	//Fetch Hexadecimal representation
				_myputs(convert(i,16));
				break;

		}
	}
endofProcess:
//	UTIL_delay(1);
	va_end(arg);

}

