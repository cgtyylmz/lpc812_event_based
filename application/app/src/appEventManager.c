#include "projectConf.h"
#include "globalDefinitions.h"
#include "appEventManager.h"


static eventStr gEventList[MAX_EVENT_NUMBER];
static U32 gIsStarted;


/**
 * @brief This function init Event Manager
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventInit(void)
{
	appEventDeleteEvents();
	gIsStarted = FALSE;

	return SUCCESS;
}

/**
 * @brief Throw the event. App procces loop will catch event
 * @param Event struct
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventThrowEvent(EVENT event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *param, U32 leng, U32 value)
{
	RETURN_STATUS retVal = FAILTURE;
	U32 i;

	for(i = 0; i < MAX_EVENT_NUMBER; i++)
	{
		if(EN_EVENT_NO_EVENT == gEventList[i].event)
		{
			gEventList[i].event = event;
			gEventList[i].source = source;
			gEventList[i].priority = priority;
			gEventList[i].param = param;
			gEventList[i].leng = leng;
			gEventList[i].value = value;

			retVal = SUCCESS;

			break;
		}
	}


	return retVal;
}


/**
 * @brief Delete all pending events.
 * @param void
 * @return void
 */
void appEventDeleteEvents(void)
{
	U32 i;

	for(i = 0; i < MAX_EVENT_NUMBER; i++)
	{
		gEventList[i].event = EN_EVENT_NO_EVENT;
	}
}

/**
 * @brief clear related event by event pointer,
 * @note  if return success event pointer loaded NULL
 * @param event ID
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventClearEvent(eventStr *event)
{
	U32 i;

	for(i = 0; i < MAX_EVENT_NUMBER; i++)
	{
		if(event == (gEventList + i))
		{
			gEventList[i].event = EN_EVENT_NO_EVENT;
			event = NULL;
			break;
		}
	}

	return 0;
}


/**
 * @brief Start to get events.
 * @param void
 * @return void
 */
void appEventStart(void)
{
	gIsStarted = TRUE;
}

/**
 * @brief Stop to get events.
 * @param void
 * @return void
 */
void appEventStop(void)
{
	gIsStarted = FALSE;
}

/**
 * @brief get event
 * @param timeout, 0 blocking mode(wait until any event created)
 * @param send a pointer to get events and events priority
 * @return if everything is OK, return event addr
 *         otherwise return NULL addr
 */
eventStr* appEventGet(U32 timeoutMs, U32 eventSource)
{
	eventStr* retAddr = NULL;
	S32 maxPri;
	U32 i;

	if(FALSE == gIsStarted)
	{
		return retAddr;
	}

	maxPri = -1;

	for(i = 0; i < MAX_EVENT_NUMBER; i++)
	{
		if((EN_EVENT_NO_EVENT !=gEventList[i].event) && (gEventList[i].priority > maxPri) && (eventSource & gEventList[i].source))
		{
			maxPri = gEventList[i].priority;
			retAddr = gEventList + i;
			if(maxPri >= EN_PRIORITY_EMG)
			{
				break;
			}
		}
	}

	return retAddr;

}

