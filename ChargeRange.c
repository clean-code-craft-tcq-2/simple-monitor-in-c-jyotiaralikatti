  #include <stdbool.h>
 #include "BMS.h"
  
  bool IsChargeRateValid(float chargeRate)
{
    if (chargeRate<=0 || chargeRate >= 0.8) {
        printf("Charge Rate out of range! for %f\n",chargeRate);
    return RANGE_NOT_OK;
    }
    return RANGE_OK;
}
  
  bool Charge_Rate(float chargeRate)
  {
  bool batteryChargeRateResult = false;
  
  batteryChargeRateResult = IsChargeRateValid(chargeRate);
  if(batteryChargeRateResult)
  {

       batteryChargeRateResult = CheckForEarlyWarning(BATTERYPARAMETER_CHARGERATE , chargeRate);

  }
  
  return batteryChargeRateResult;
  }
