#include "middMcuCore.h"
#include "projectConf.h"


/**
  * @brief Init MCU CORE And MCU Clock
  * @param void
  * @param If evertthins is OK return SUCCESS otherwise return FAILTURE
*/
RETURN_STATUS middMCUClockInit(void)
{
	MCU_CORE_INIT();
	MCU_CLOCK_CONF();
	return SUCCESS;
}

/**
  * @brief Init MCU GPIO
  * @param void
  * @param If evertthins is OK return SUCCESS otherwise return FAILTURE
*/
RETURN_STATUS middMCUGpioInit(void)
{
	GPIO_INIT();
	return SUCCESS;
}

/**
  * @brief Init MCU Timers
  * @param void
  * @param If evertthins is OK return SUCCESS otherwise return FAILTURE
*/
RETURN_STATUS middMCUTimerInit(void)
{
	TIMER_EVENT_INIT();
	return SUCCESS;
}
