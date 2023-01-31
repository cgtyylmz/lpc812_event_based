#include "middSerialComm.h"
#include "generalBoardConfig.h"

RETURN_STATUS middSerialCommInit()
{
	DGB_UART_INIT();

	return 0;
}

