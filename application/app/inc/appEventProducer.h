#ifndef __APP_EVENT_PRODUCER__
#define __APP_EVENT_PRODUCER__

#include "projectConf.h"
#include "appEventManager.h"


/**
 * @brief  set digital io event
 * @param  TRUE for receive event, FALSE is stop
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventProdDigitalIO(uint8_t stat, EVENT_PRIORITY prio);

/**
 * @brief  set periodic timer event
 * @param  TRUE for receive event, FALSE is stop
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEvntProdPerTimer(timerId tmid, U32 time, uint8_t status, EVENT_PRIORITY prio);

/**
 * @brief  stop all event producers
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEvntProdStopAll(void);


#endif // __APP_EVENT_PRODUCER__

