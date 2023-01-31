#ifndef PROJECT_CONF_H
#define PROJECT_CONF_H


/******************************** INCLUDES ************************************/
#include "generalBoardConfig.h"
#include "globalDefinitions.h"

/***************************** MACROS *****************************************/

#define MIN_TIMER_PERIOD_MS		(10)
#define STATUS_TIME 			(WAIT_100_MS)
#define COMM_TIME 				(WAIT_2_SEC)
#define DATA_TIME 				(WAIT_3_SEC)

/***************************** VARIABLES **************************************/

#define ALL_DBG_MSG 			0

#if (ALL_DBG_MSG || PAGE_DBG_MSG)

#define DGB_MSG(x) 				DGB_UART_SEND(x)

#else
#define DGB_MSG(x)
#endif

typedef enum _timerId
{
	EN_TIMER_STATUS,
	EN_TIMER_COMM,
	EN_TIMER_DATA,
	EN_TIMER_MAX_NUM
}timerId;


#endif // PROJECT_CONF_H

