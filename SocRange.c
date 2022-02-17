#include <stdbool.h>
#include "BMS.h"

bool IsSOCValid(float soc)
{
    if(soc <= 20 || soc >= 80) {
        printf("State of Charge out of range! for %f\n",soc);
    return RANGE_NOT_OK;
    }
    return RANGE_OK;
}

bool State_Range(float soc)
  bool SOCResult = false;
 
  SOCResult = IsSOCValid(soc);
  if(SOCResult)
  {
      SOCResult = CheckForEarlyWarning(BATTERYPARAMETER_SOC, soc);
  }
  
  return SOCResult;
  }
