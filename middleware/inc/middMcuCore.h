#ifndef MIDD_MCU_CORE_H
#define MIDD_MCU_CORE_H

#include "globalDefinitions.h"

/**
  * @brief Init MCU CORE And MCU Clock
  * @param void
  * @param If evertthins is OK return SUCCESS otherwise return FAILTURE
*/
RETURN_STATUS middMCUClockInit(void);

/**
  * @brief Init MCU GPIO
  * @param void
  * @param If evertthins is OK return SUCCESS otherwise return FAILTURE
*/
RETURN_STATUS middMCUGpioInit(void);

/**
  * @brief Init MCU Timers
  * @param void
  * @param If evertthins is OK return SUCCESS otherwise return FAILTURE
*/
RETURN_STATUS middMCUTimerInit(void);

#endif // MIDD_MCU_CORE_H

