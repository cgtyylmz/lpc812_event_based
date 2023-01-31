#include "appMainLoop.h"
#include "appSystemSetup.h"
#include "appEventManager.h"
#include "appWorkingModeManager.h"
#include "appEventHandler.h"

RETURN_STATUS appMLRun(void)
{
	eventStr *event;

	appSystemSetup();
	appEventStart();

	while(1)
	{

		event = appEventGet(0, EN_SOURCE_ALL);
		if(NULL != event)
		{
			appEventHandler(event);
			appEventClearEvent(event);
		}
	}
	return 0;
}

