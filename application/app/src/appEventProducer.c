#include "appEventProducer.h"
#include "middEventTimer.h"
#include "middDigitalIO.h"

static union
{
	U32 priVal;
	struct
	{
		EVENT_PRIORITY timerPrio  : 2;
		EVENT_PRIORITY keysPrio   : 2;
	};
}gEventPriority;

static void cbDataTime(void)
{
	appEventThrowEvent(EN_EVENT_DATA_TIME, EN_SOURCE_PER_TIMER, gEventPriority.timerPrio, NULL, 0, 0);
}

static void cbStatusTime(void)
{
	appEventThrowEvent(EN_EVENT_STATUS_TIME, EN_SOURCE_PER_TIMER, gEventPriority.timerPrio, NULL, 0, 0);
}

static void cbKeys(uint32_t key)
{
	appEventThrowEvent(EN_EVENT_KEYS, EN_SOURCE_INTERNAL, gEventPriority.keysPrio, NULL, 0, 0);
}

/**
 * @brief  set digital io event
 * @param  TRUE for receive event, FALSE is stop
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventProdDigitalIO(uint8_t stat, EVENT_PRIORITY prio)
{
	RETURN_STATUS retVal = FALSE;

	gEventPriority.keysPrio = prio;
	middIOListener(cbKeys);

	return retVal;
}

/**
 * @brief  set periodic timer event
 * @param  TRUE for receive event, FALSE is stop
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEvntProdPerTimer(timerId tmid, U32 period, uint8_t status, EVENT_PRIORITY prio)
{
	RETURN_STATUS retVal = FALSE;

	gEventPriority.timerPrio = prio;


	if(tmid == EN_TIMER_DATA)
	{
		middEventTimerRegister(tmid, cbDataTime, period);
		middEventTimerStart(tmid);
	}

	if(tmid == EN_TIMER_STATUS)
	{
		middEventTimerRegister(tmid, cbStatusTime, period);
	}

	return retVal;
}

/**
 * @brief  stop all event producers
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEvntProdStopAll(void)
{
	RETURN_STATUS retVal = FALSE;

	return retVal;
}

