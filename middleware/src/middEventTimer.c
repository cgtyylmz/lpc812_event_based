#include "middEventTimer.h"
#include "projectConf.h"
#include "mcuInterruptRegister.h"
#include "generalBoardConfig.h"

/****************************** TYPE DEFINATIONS ******************************/

typedef struct _timerStr
{
	U32 timeout;
	VoidCallback callback;
	U32 timeoutCopy;
}timerStr;

/****************************** VARIABLES *************************************/

static volatile timerStr timerCallBackList[EN_TIMER_MAX_NUM];

/****************************** STATIC FUNCTIONS ******************************/
static void timerEvetCallback(int x)
{
	static U32 i;
	for(i = 0; i < EN_TIMER_MAX_NUM; i++)
	{
		if(timerCallBackList[i].timeout > 0)
		{
			timerCallBackList[i].timeout -= MIN_TIMER_PERIOD_MS;

			if(timerCallBackList[i].timeout < MIN_TIMER_PERIOD_MS)
			{
				timerCallBackList[i].timeout = timerCallBackList[i].timeoutCopy;
				timerCallBackList[i].callback();
			}
		}
	}
}

/****************************** GLOBAL FUNCTIONS ******************************/

/**
  * @brief Initialize Event Timer
  * @param void
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerInit(void)
{
	RETURN_STATUS retVal;
	U32 i = 0;

	for(i = 0; i < EN_TIMER_MAX_NUM; i++)
	{
		timerCallBackList[i].timeout = 0;
		timerCallBackList[i].callback = NULL;
	}

	retVal = drvIntRegister(timerEvetCallback, TIMER_EVENT_IT_ID);

	return retVal;
}

/**
  * @brief Register Event to EventTimer
  * @param timerId
  * @param callback Callback Function
  * @param timeMs event time millisecond
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerRegister(timerId id, VoidCallback callback, U32 timeMs)
{
	RETURN_STATUS retVal = FAILTURE;
	U32 ru;

	ru = (timeMs % MIN_TIMER_PERIOD_MS);
	if(0 != ru)
	{
		timeMs += MIN_TIMER_PERIOD_MS - ru;
	}

	timerCallBackList[id].callback = callback;
	timerCallBackList[id].timeout = 0;
	timerCallBackList[id].timeoutCopy = timeMs;

	retVal = SUCCESS;

	return retVal;
}

/**
  * @brief Start Event Timer
  * @param timerId timer id
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerStart(timerId id)
{
	RETURN_STATUS retVal = SUCCESS;

	timerCallBackList[id].timeout = timerCallBackList[id].timeoutCopy;

	return retVal;
}

/**
  * @brief Stop Event Timer
  * @param timerId timer id
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerStop(timerId id)
{
	RETURN_STATUS retVal = SUCCESS;

	timerCallBackList[id].timeout = 0;

	return retVal;
}

