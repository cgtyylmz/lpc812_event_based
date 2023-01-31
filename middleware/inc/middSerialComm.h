#ifndef __MIDD_SERIAL_COMM__
#define __MIDD_SERIAL_COMM__

#include "globalDefinitions.h"
#include "generalBoardConfig.h"

RETURN_STATUS middSerialCommInit(void);

#define  middSerialSend(x) DGB_UART_SEND(x)


#endif // __MIDD_SERIAL_COMM__

