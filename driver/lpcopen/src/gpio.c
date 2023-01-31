#include "gpio.h"
#include "chip.h"

void initGpio(void)
{

	// Led Pin Config
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, STATUS_LED_PORT, STATUS_LED_PIN);

	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);
	// Enable Usart pins
	// GPIO 11 as TXD
	// GPIO 10 as RXD
	Chip_SWM_MovablePinAssign(SWM_U1_TXD_O, DEBUG_TX_PIN);
	Chip_SWM_MovablePinAssign(SWM_U1_RXD_I, DEBUG_RX_PIN);

	// Enable Interrupt on GPIO0_3
	Chip_SWM_DisableFixedPin(SWM_FIXED_SWCLK);
	Chip_SYSCTL_SetPinInterrupt(0, USER_BUTTON);
	Chip_GPIO_SetPinDIRInput(LPC_GPIO_PORT, 0, USER_BUTTON);

	Chip_PININT_SetPinModeEdge(LPC_PININT, USER_BUTTON);
	Chip_PININT_EnableIntHigh(LPC_PININT, USER_BUTTON);
	Chip_PININT_GetHighEnabled(LPC_PININT);

	NVIC_EnableIRQ(PININT0_IRQn);


	Chip_Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);

	Chip_GPIO_Init(LPC_GPIO_PORT);
}

