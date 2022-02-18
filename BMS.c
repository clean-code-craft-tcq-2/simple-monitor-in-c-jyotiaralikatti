
#include <assert.h>
#include <stdbool.h>
#include "BMS.h"

bool Temp_Range(float );
bool State_Range(float );
bool Charge_Rate(float );
bool LogicalAND(float,float);

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
  UNUSED(BatteryParameterValue);
  /*EarlyWarning = IsToleranceLowerLimitApproached(BatteryParameter);
  if(!EarlyWarning)
  {
    EarlyWarning = IsToleranceUpperLimitApproached(BatteryParameter,BatteryParameterValue);
  }*/
  
  return EarlyWarning;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7,&Temp_Range,&State_Range ,&Charge_Rate));
  assert(!batteryIsOk(50, 85, 0,&Temp_Range,&State_Range ,&Charge_Rate));
  
    assert(!batteryIsOk(30, 85, 0.1,&Temp_Range,&State_Range ,&Charge_Rate));
  assert(!batteryIsOk(25, 70, 0.9,&Temp_Range,&State_Range ,&Charge_Rate));
}

