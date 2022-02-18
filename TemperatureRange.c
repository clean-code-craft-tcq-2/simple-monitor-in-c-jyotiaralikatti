
#include <stdio.h>
#include <stdbool.h>
#include "BMS.h"

bool IsTemperatureValid(float temperature)
{
    if(temperature <= 0 || temperature >= 45) {
        printf("Temperature out of range! for %f\n",temperature);
    return RANGE_NOT_OK; 
    }
    return RANGE_OK;
    
    
}
bool Temp_Range(float temperature)
{
  bool batteryTemperatureResult = false;
  
  batteryTemperatureResult = IsTemperatureValid(temperature);
  
  if(batteryTemperatureResult)
  {

      batteryTemperatureResult = CheckForEarlyWarning(BATTERYPARAMETER_TEMPERATURE, temperature);
 
  }
  
  return batteryTemperatureResult;
}
