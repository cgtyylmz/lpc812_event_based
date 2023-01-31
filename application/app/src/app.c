#include "app.h"
#include "middDigitalIO.h"
#include "middSerialComm.h"
#include "middEventTimer.h"

#include "uart.h"

int status = 0;

RETURN_STATUS appHandleDataTime(void)
{
	middSerialSend(("DATA TIME\r\n"));
	return 0;
}

RETURN_STATUS appHandleStatusTime(void)
{
	middIOToggleStatusLed();
	return 0;
}

RETURN_STATUS appHandleKey(void)
{
	if(status == 0)
	{
		middEventTimerStart(EN_TIMER_STATUS);
		status = 1;
	}

	else
	{
		middEventTimerStop(EN_TIMER_STATUS);
		status = 0;
	}
	return 0;
}

