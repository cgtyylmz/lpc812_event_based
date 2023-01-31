#ifndef __APP_EVENT_MANAGER__
#define __APP_EVENT_MANAGER__

/***************************** INCLUDES ***************************************/
#include "globalDefinitions.h"
#include "projectConf.h"

/****************************** DEFINES ***************************************/
#define MAX_EVENT_NUMBER 		(32)

/****************************** VARIABLES *************************************/
typedef enum _EVENTS
{
	EN_EVENT_NO_EVENT,
	EN_EVENT_DATA_TIME,
	EN_EVENT_STATUS_TIME,
	EN_EVENT_KEYS
}EVENT;

typedef enum _EVENT_PRIORITY
{
	EN_PRIORITY_LOW,
	EN_PRIORITY_MED,
	EN_PRIORITY_HIGH,
	EN_PRIORITY_EMG
}EVENT_PRIORITY;

typedef enum _EVENT_SOURCE
{
	EN_SOURCE_PER_TIMER = 0x01,
	EN_SOURCE_INTERNAL  = 0x02,
	EN_SOURCE_ALL       = 0x3FF
}EVENT_SOURCE;

typedef struct _eventStr
{
	U32 		 	event 	 :10;
	EVENT_SOURCE 	source 	 :10;
	U32 			leng 	 :10;
	EVENT_PRIORITY  priority :2;
	U32 			value;
	void* 			param;
}eventStr;

/**
 * @brief This function init Event Manager
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventInit(void);

/**
 * @brief Throw the event. App procces loop will catch event
 * @param Event struct
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventThrowEvent(EVENT event, EVENT_SOURCE source, EVENT_PRIORITY priority, void *param, U32 leng, U32 value);


/**
 * @brief Delete all pending events.
 * @param void
 * @return void
 */
void appEventDeleteEvents(void);

/**
 * @brief Start to get events.
 * @param void
 * @return void
 */
void appEventStart(void);

/**
 * @brief Stop to get events.
 * @param void
 * @return void
 */
void appEventStop(void);

/**
 * @brief clear related event by event pointer,
 * @note  if return success event pointer loaded NULL
 * @param event ID
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventClearEvent(eventStr *event);

/**
 * @brief get event
 * @param timeout, 0 blocking mode(wait until any event created)
 * @param send a pointer to get events and events priority
 * @return if everything is OK, return event addr
 *         otherwise return NULL addr
 */
eventStr* appEventGet(U32 timeoutMs, U32 eventSource);

#endif // __APP_EVENT_MANAGER__

