#include "globalDefinitions.h"
#include "projectConf.h"

#include "appWorkingModeManager.h"
#include "appEventManager.h"
#include "appEventProducer.h"
#include "app.h"



RETURN_STATUS setWorkingMode(void)
{
	appEvntProdStopAll();
	appEventDeleteEvents();

	appEventProdDigitalIO(0, EN_PRIORITY_MED);
	appEvntProdPerTimer(EN_TIMER_DATA, WAIT_2_SEC, 0, EN_PRIORITY_MED);
	appEvntProdPerTimer(EN_TIMER_STATUS, STATUS_TIME, 0, EN_PRIORITY_MED);

	TIMER_EVENT_START();

	return 0;
}

