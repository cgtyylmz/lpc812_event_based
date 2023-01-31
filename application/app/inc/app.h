#ifndef __APP_H__
#define __APP_H__

#include "globalDefinitions.h"
#include "projectConf.h"


/**
 * @brief  Handle Data Timer Event
 * @param  void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appHandleDataTime(void);

/**
 * @brief  Handle Status Led Timer
 * @param  void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appHandleStatusTime(void);

/**
 * @brief  Handle Button Event
 * @param  TRUE for receive event, FALSE is stop
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS appHandleKey(void);


#endif //__APP_H__

