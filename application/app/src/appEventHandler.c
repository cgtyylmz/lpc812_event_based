#include "appEventHandler.h"
#include "appEventManager.h"
#include "app.h"

#include "middSerialComm.h"
#include "uart.h"


#define PAGE_DBG_MSG 	ENABLE_T


RETURN_STATUS appEventHandler(const eventStr *event)
{
	switch(event->event)
	{
		case EN_EVENT_DATA_TIME:
			{
				appHandleDataTime();
				break;
			}

		case EN_EVENT_STATUS_TIME:
			{
				appHandleStatusTime();
				break;
			}

		case EN_EVENT_KEYS:
			{
				appHandleKey();
				break;
			}
	}

	return 0;
}

