#ifndef MIDD_EVENT_TIMER_H
#define MIDD_EVENT_TIMER_H

/****************************** INCULDES **************************************/

#include "projectConf.h"

/****************************** GLOBAL FUNCTIONS ******************************/

/**
  * @brief Initialize Event Timer
  * @param void
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerInit(void);

/**
  * @brief Regiter Event to Event Timer
  * @param timerId
  * @param callback Callback Function
  * @param timeMs event time millisecond
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerRegister(timerId id, VoidCallback callback, U32 timeMs);

/**
  * @brief Start Event Timer
  * @param timerId timer id
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerStart(timerId);

/**
  * @brief Stop Event Timer
  * @param timerId timer id
  * @return If everything is OK return SUCCESS else return FAILTURE
*/
RETURN_STATUS middEventTimerStop(timerId);

#endif
