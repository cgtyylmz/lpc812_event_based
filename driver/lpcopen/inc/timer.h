#ifndef __TIMER_H__
#define __TIMER_H__

#include "chip.h"

static void setupMRT(uint8_t ch, MRT_MODE_T mode, uint32_t rate);

void initTimer(void);

void timerStartMRT(void);

#endif // __TIMER_H__

