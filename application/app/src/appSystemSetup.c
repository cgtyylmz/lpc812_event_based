#include "appSystemSetup.h"

#include "appEventManager.h"
#include "appEventProducer.h"
#include "appWorkingModeManager.h"

#include "middMcuCore.h"
#include "middDigitalIO.h"
#include "middEventTimer.h"
#include "middSerialComm.h"


static RETURN_STATUS setupInitMcuCore(void)
{
	middMCUClockInit();
	middMCUGpioInit();
	middMCUTimerInit();
	return 0;
}

static RETURN_STATUS initSWRequirement(void)
{
	middIOinit();
	middEventTimerInit();
	middSerialCommInit();

	appEventInit();
	return 0;
}

RETURN_STATUS appSystemSetup(void)
{
	setupInitMcuCore();
	initSWRequirement();
	setWorkingMode();

	return 0;
}

