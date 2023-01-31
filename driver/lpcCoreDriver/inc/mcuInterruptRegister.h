#ifndef __MCU_INTERRUPT_REGISTER__
#define __MCU_INTERRUPT_REGISTER__

#include "projectConf.h"

RETURN_STATUS drvIntRegister(VICallback callback, EN_INTERRUPT_LIST intType);

RETURN_STATUS drvIntUnRegister(EN_INTERRUPT_LIST intType);

#endif // __MCU_INTERRUPT_REGISTER__

