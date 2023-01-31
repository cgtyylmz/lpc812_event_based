#include "middMcuCore.h"
#include "middEventTimer.h"
#include "generalBoardConfig.h"
#include "projectConf.h"
#include "generalBoardConfig.h"
#include "appSystemSetup.h"
#include "appMainLoop.h"

const uint32_t OscRateIn = 0;
const uint32_t ExtRateIn = 12000000;


int main()
{
	appSystemSetup();
	appMLRun();

	return 0;
}

