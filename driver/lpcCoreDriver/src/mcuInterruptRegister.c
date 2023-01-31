#include "mcuInterruptRegister.h"
#include "projectConf.h"

static VICallback gInterruptCallbackList[EN_INTERRUPT_LIST_MAX_NUM];

static void runCallback(EN_INTERRUPT_LIST intType, int value)
{
	gInterruptCallbackList[intType](value);
}

CORE_EXT_IT_FUNCTION
{
	Chip_PININT_ClearIntStatus(LPC_PININT, PININTCH0);
	runCallback(GPIO_EXT_INT_ID, 0);
}

CORE_TIMER_IT_FUNCTION
{
	uint32_t int_pend;

	/* Get interrupt pending status for all timers */
	int_pend = Chip_MRT_GetIntPending();
	Chip_MRT_ClearIntPending(int_pend);

	runCallback(TIMER_EVENT_IT_ID, 0);

}


RETURN_STATUS drvIntRegister(VICallback callbackFunc, EN_INTERRUPT_LIST intType)
{
	gInterruptCallbackList[intType] = callbackFunc;

	return SUCCESS;
}

RETURN_STATUS drvIntUnRegister(EN_INTERRUPT_LIST intType)
{
	gInterruptCallbackList[intType] = NULL;

	return SUCCESS;
}

