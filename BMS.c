#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool Temp_Range(float );
bool State_Range(float );
bool Charge_Rate(float );
bool LogicalAND(float,float);

#define RANGE_OK 1
#define RANGE_NOT_OK 0

bool batteryIsOk(float temperature, float soc, float chargeRate,bool(*Temp_RangeFtr)(float),bool(*State_RangeFtr)(float),bool(*Charge_RateFtr)(float)) {  
bool TemperatureResult,SocResult,ChargerateResult,Battery_status=0;
    TemperatureResult = Temp_RangeFtr(temperature);
    SocResult = State_RangeFtr(soc);
    ChargerateResult = Charge_RateFtr(chargeRate);
    
  return (TemperatureResult || SocResult || ChargerateResult);;
}



bool CheckForEarlyWarning(int BatteryParameter, float BatteryParameterValue)
{
  int EarlyWarning = false;
  
  /*EarlyWarning = IsToleranceLowerLimitApproached(BatteryParameter);
  if(!EarlyWarning)
  {
    EarlyWarning = IsToleranceUpperLimitApproached(BatteryParameter,BatteryParameterValue);
  }*/
  
  return EarlyWarning;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  
    assert(!batteryIsOk(30, 85, 0.1));
  assert(!batteryIsOk(25, 70, 0.9));
}
