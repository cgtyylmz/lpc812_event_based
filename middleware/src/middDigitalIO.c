#include "middDigitalIO.h"
#include "mcuInterruptRegister.h"

static VUICallback cbListener;

static void cbGPIOInt(int key)
{
	cbListener(key);
}

/**
 * @brief  init digital IO
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOinit(void)
{
	drvIntRegister(cbGPIOInt, EN_PININT0_IRQn);

	return 0;
}

/**
 * @brief  listen gpio in
 * @param  callback function
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOListener(VUICallback cb)
{
	cbListener = cb;

	return 0;
}

RETURN_STATUS middIOToggleStatusLed(void)
{
	TOGGLE_LED_1();
	return 0;
}

