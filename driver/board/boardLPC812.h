#ifndef __BOARD_LPC812__
#define __BOARD_LPC812__

/******************************* INCLUDES *************************************/

#include "main.h"
#include "chip.h"
#include "gpio.h"
#include "uart.h"
#include "timer.h"


typedef enum _EN_INTERRUPT_LIST
{
	/******  LPC8xx Specific Interrupt Numbers ********************************************************/
//	EN_SPI0_IRQn,                       	/*!< SPI0                                             */
//	EN_SPI1_IRQn,                       	/*!< SPI1                                             */
//	EN_Reserved0_IRQn,                  	/*!< Reserved Interrupt                               */
//	EN_UART0_IRQn,                      	/*!< USART0                                           */
//	EN_UART1_IRQn,                      	/*!< USART1                                           */
//	EN_UART2_IRQn,                      	/*!< USART2                                           */
//	EN_Reserved1_IRQn,                  	/*!< Reserved Interrupt                               */
//	EN_Reserved2_IRQn,                  	/*!< Reserved Interrupt                               */
//	EN_I2C0_IRQn,                       	/*!< I2C0                                             */
//	EN_I2C_IRQn,                        	/*!< Alias for I2C0                                   */
//	EN_SCT_IRQn,                        	/*!< SCT                                              */
	EN_MRT_IRQn,                      		/*!< MRT                                              */
//	EN_CMP_IRQn,                      		/*!< CMP                                              */
//	EN_WDT_IRQn,                      		/*!< WDT                                              */
//	EN_BOD_IRQn,                      		/*!< BOD                                              */
//	EN_FLASH_IRQn,                    		/*!< Flash interrupt                                  */
//	EN_WKT_IRQn,                      		/*!< WKT Interrupt                                    */
//	EN_Reserved4_IRQn,                		/*!< Reserved Interrupt                               */
//	EN_Reserved5_IRQn,                		/*!< Reserved Interrupt                               */
//	EN_Reserved6_IRQn,                		/*!< Reserved Interrupt                               */
//	EN_Reserved7_IRQn,                		/*!< Reserved Interrupt                               */
//	EN_Reserved8_IRQn,                		/*!< Reserved Interrupt                               */
//	EN_Reserved9_IRQn,                		/*!< Reserved Interrupt                               */
//	EN_Reserved10_IRQn,               		/*!< Reserved Interrupt                               */
//	EN_Reserved11_IRQn,               		/*!< Reserved Interrupt                               */
	EN_PININT0_IRQn,                  		/*!< External Interrupt 0                             */
//	EN_PIN_INT0_IRQn,                 		/*!< External Interrupt 0 (alias)                     */
//	EN_PININT1_IRQn,                  		/*!< External Interrupt 1                             */
//	EN_PIN_INT1_IRQn,                 		/*!< External Interrupt 1 (alias)                     */
//	EN_PININT2_IRQn,                  		/*!< External Interrupt 2                             */
//	EN_PIN_INT2_IRQn,                 		/*!< External Interrupt 2 (alias)                     */
//	EN_PININT3_IRQn,                  		/*!< External Interrupt 3                             */
//	EN_PIN_INT3_IRQn,                 		/*!< External Interrupt 3 (alias)                     */
//	EN_PININT4_IRQn,                  		/*!< External Interrupt 4                             */
//	EN_PIN_INT4_IRQn,                 		/*!< External Interrupt 4 (alias)                     */
//	EN_PININT5_IRQn,                  		/*!< External Interrupt 5                             */
//	EN_PIN_INT5_IRQn,                 		/*!< External Interrupt 5 (alias)                     */
//	EN_PININT6_IRQn,                  		/*!< External Interrupt 6                             */
//	EN_PIN_INT6_IRQn,                 		/*!< External Interrupt 6 (alias)                     */
//	EN_PININT7_IRQn,                  		/*!< External Interrupt 7                             */
//	EN_PIN_INT7_IRQn,                 		/*!< External Interrupt 7 (alias)                     */

    EN_INTERRUPT_LIST_MAX_NUM, // dont move this line
}_EN_INTERRUPT_LIST;

/********************* Board MCU and Clock Control ****************************/

#define _MCU_CORE_INIT() 				Chip_SystemInit()
#define _MCU_CLOCK_CONF() 				SystemCoreClockUpdate()

#define _DELAY_MS(x)

/********************* Board GPIO Control *************************************/

#define _GPIO_INIT()					initGpio()

#define _GPIO_WRITE(port, pin, status)  Chip_GPIO_WritePortBit(LPC_GPIO_PORT, port, pin, status)
#define _GPIO_TOGGLE(port, pin)			Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,port, pin)
#define _GPIO_READ(port, pin)			Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, port, pin)

#define _LED_1(x)						Chip_GPIO_WritePortBit(LPC_GPIO_PORT ,STATUS_LED_PORT, STATUS_LED_PIN, x)
#define _TOGGLE_LED_1()					Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, STATUS_LED_PORT, STATUS_LED_PIN);
#define _CORE_EXT_IT_FUCTION 			void PININT0_IRQHandler(void)
#define _GPIO_EXT_INT_ID 				EN_PININT0_IRQn
/******************** BOARD TIMER CONTROL *************************************/

#define _TIMER_EVENT_INIT()				initTimer()

#define _CORE_TIMER_IT_FUNCTION			void MRT_IRQHandler(void)

#define _TIMER_EVENT_START()			timerStartMRT()
#define _TIMER_EVENT_IT_ID				EN_MRT_IRQn

/******************** BOARD TIMER CONTROL *************************************/

#define _DBG_UART_INIT() 				initUART1()
#define _DBG_UART_SEND(x) 		        _myprintf x
/******************************************************************************/
#endif  // __BOARD_LPC812__

