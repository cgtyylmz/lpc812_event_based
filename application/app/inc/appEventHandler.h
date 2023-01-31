#ifndef __APP_EVENT_HANDLER__
#define __APP_EVENT_HANDLER__

#include "globalDefinitions.h"
#include "projectConf.h"
#include "appEventManager.h"

/**
 * @brief  Call event Handler function
 * @param  Event Struct
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appEventHandler(const eventStr* event);

#endif // __APP_EVENT_HANDLER__

