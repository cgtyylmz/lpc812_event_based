#ifndef GENERAL_BOARD_CONFIG_H
#define GENERAL_BOARD_CONFIG_H

#include "boardLPC812.h"

typedef _EN_INTERRUPT_LIST EN_INTERRUPT_LIST;

/********************* Board MCU and Clock Control ****************************/

#define MCU_CORE_INIT() 				_MCU_CORE_INIT()
#define MCU_CLOCK_CONF() 				_MCU_CLOCK_CONF()

#define DELAY_MS(x)						_DELAY_MS(x)

/********************* Board GPIO Control *************************************/

#define GPIO_INIT()						_GPIO_INIT()

#define GPIO_WRITE(port, pin, status)	_GPIO_WRITE(port, pin, status)
#define GPIO_TOGGLE(port, pin)			_GPIO_TOGGLE(port, pin)
#define GPIO_READ(port, pin)			_GPIO_READ(port, pin)

#define LED_1(x)						_LED_1(x)
#define TOGGLE_LED_1()					_TOGGLE_LED_1()

#define GPIO_EXT_INT_ID 				_GPIO_EXT_INT_ID
#define CORE_EXT_IT_FUNCTION 			_CORE_EXT_IT_FUCTION

/******************** BOARD TIMER CONTROL *************************************/

#define TIMER_EVENT_INIT()				_TIMER_EVENT_INIT()

#define CORE_TIMER_IT_FUNCTION			_CORE_TIMER_IT_FUNCTION

#define TIMER_EVENT_START()				_TIMER_EVENT_START()
#define TIMER_EVENT_IT_ID				_TIMER_EVENT_IT_ID

/******************** BOARD UART CONTROL *************************************/

#define DGB_UART_INIT() 				_DBG_UART_INIT()
#define DGB_UART_SEND(x) 				_DBG_UART_SEND(x)

#endif  // GENERAL_BOARD_CONFIG_H

