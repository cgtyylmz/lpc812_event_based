#include "chip.h"

static void setupMRT(uint8_t ch, MRT_MODE_T mode, uint32_t rate)
{
	LPC_MRT_CH_T *pMRT;

	/* Get pointer to timer selected by ch */
	pMRT = Chip_MRT_GetRegPtr(ch);

	/* Setup timer with rate based on MRT clock */
	Chip_MRT_SetInterval(pMRT, (Chip_Clock_GetSystemClockRate() / rate) |
						 MRT_INTVAL_LOAD);

	/* Timer mode */
	Chip_MRT_SetMode(pMRT, mode);

	/* Clear pending interrupt and enable timer */
	Chip_MRT_IntClear(pMRT);
}


void initTimer(void)
{
	Chip_MRT_Init();
	Chip_MRT_SetDisabled(0);
	NVIC_EnableIRQ(MRT_IRQn);

	setupMRT(0, MRT_MODE_REPEAT, 100);
}

void timerStartMRT(void)
{
	LPC_MRT_CH_T *pMRT;

	/* Get pointer to timer selected by ch */
	pMRT = Chip_MRT_GetRegPtr(0);
	Chip_MRT_SetEnabled(pMRT);
}

