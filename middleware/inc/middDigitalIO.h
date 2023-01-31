#ifndef __MIDD_DIGITAL_IO_H__
#define __MIDD_DIGITAL_IO_H__

#include "globalDefinitions.h"


/**
 * @brief  init digital IO
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOinit(void);

/**
 * @brief  listen gpio in
 * @param  callback function
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOListener(VUICallback cb);

RETURN_STATUS middIOToggleStatusLed(void);

#endif // __MIDD_DIGITAL_IO_H__

