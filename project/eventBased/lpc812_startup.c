#include "stdint.h"

#define SRAM_START 0x10000000
#define SRAM_SIZE  (4)
#define SRAM_END   ((SRAM_START) + (SRAM_SIZE) * 1024)

#define STACK_START SRAM_END
#define WEAK __attribute__ ((weak))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

int main(void);
void SystemInit(void);

extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _etext;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _lo_data;

void Reset_Handler(void);
void NMI_Handler(void) ALIAS(Default_Handler);                            // The NMI handler
void HardFault_Handler(void) ALIAS(Default_Handler);                      // The hard fault handler
void SVC_Handler(void) ALIAS(Default_Handler);                            // SVCall handler
void PendSV_Handler(void) ALIAS(Default_Handler);                         // The PendSV handler
void SysTick_Handler(void) ALIAS(Default_Handler);                        // The SysTick handler
void SPI0_IRQHandler(void) ALIAS(Default_Handler);                         // SPI0 controller
void SPI1_IRQHandler(void) ALIAS(Default_Handler);                         // SPI1 controller
void UART0_IRQHandler(void) ALIAS(Default_Handler);                        // UART0
void UART1_IRQHandler(void) ALIAS(Default_Handler);                        // UART1
void UART2_IRQHandler(void) ALIAS(Default_Handler);                        // UART2
void I2C_IRQHandler(void) ALIAS(Default_Handler);                          // I2C controller
void SCT_IRQHandler(void) ALIAS(Default_Handler);                          // Smart Counter Timer
void MRT_IRQHandler(void) ALIAS(Default_Handler);                          // Multi-Rate Timer
void CMP_IRQHandler(void) ALIAS(Default_Handler);                          // Comparator
void WDT_IRQHandler(void) ALIAS(Default_Handler);                          // Watchdog
void BOD_IRQHandler(void) ALIAS(Default_Handler);                          // Brown Out Detect
void WKT_IRQHandler(void) ALIAS(Default_Handler);                          // Wakeup timer
void PININT0_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT0
void PININT1_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT1
void PININT2_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT2
void PININT3_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT3
void PININT4_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT4
void PININT5_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT5
void PININT6_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT6
void PININT7_IRQHandler(void) ALIAS(Default_Handler);                      // PIO INT7




uint32_t vector_table[] __attribute__ ((section(".isr_vector"))) = {
    STACK_START,
	(uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,                            // The NMI handler
    (uint32_t)HardFault_Handler,                      // The hard fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    (uint32_t)SVC_Handler,                            // SVCall handler
    0,                                      // Reserved
    0,                                      // Reserved
    (uint32_t)PendSV_Handler,                         // The PendSV handler
    (uint32_t)SysTick_Handler,                        // The SysTick handler

    // Chip Level - LPC8xx
    (uint32_t)SPI0_IRQHandler,                         // SPI0 controller
    (uint32_t)SPI1_IRQHandler,                         // SPI1 controller
    0,                                       // Reserved
    (uint32_t)UART0_IRQHandler,                        // UART0
    (uint32_t)UART1_IRQHandler,                        // UART1
    (uint32_t)UART2_IRQHandler,                        // UART2
    0,                                       // Reserved
    0,                                       // Reserved
    (uint32_t)I2C_IRQHandler,                          // I2C controller
    (uint32_t)SCT_IRQHandler,                          // Smart Counter Timer
    (uint32_t)MRT_IRQHandler,                          // Multi-Rate Timer
    (uint32_t)CMP_IRQHandler,                          // Comparator
    (uint32_t)WDT_IRQHandler,                          // Watchdog
    (uint32_t)BOD_IRQHandler,                          // Brown Out Detect
    0,                                       // Reserved
    (uint32_t)WKT_IRQHandler,                          // Wakeup timer
    0,                                       // Reserved
    0,                                       // Reserved
    0,                                       // Reserved
    0,                                       // Reserved
    0,                                       // Reserved
    0,                                       // Reserved
    0,                                       // Reserved
    0,                                       // Reserved
    (uint32_t)PININT0_IRQHandler,                      // PIO INT0
    (uint32_t)PININT1_IRQHandler,                      // PIO INT1
    (uint32_t)PININT2_IRQHandler,                      // PIO INT2
    (uint32_t)PININT3_IRQHandler,                      // PIO INT3
    (uint32_t)PININT4_IRQHandler,                      // PIO INT4
    (uint32_t)PININT5_IRQHandler,                      // PIO INT5
    (uint32_t)PININT6_IRQHandler,                      // PIO INT6
    (uint32_t)PININT7_IRQHandler,                      // PIO INT7
};

void Reset_Handler(void)
{
	// copy data flash to sram
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t *pDest = (uint8_t*)&_sdata;
	uint8_t *pSrc = (uint8_t*)&_etext;

	for(uint32_t i = 0; i < size; i++)
	{
		*pDest++ = *pSrc++;
	}

	// initialize bss section
	size = (uint32_t)&_edata - (uint32_t)&_sdata;

	for(uint32_t i = 0; i < size; i++)
	{
		*pDest++ = 0;
	}
	/* SystemInit(); */
	// call main()
	main();
}

void Default_Handler(void)
{
	while(1);

}

