#include <stdio.h>
#include <assert.h>

int Temp_Range(float );
int State_Range(float );
int Charge_Range(float );

#define RANGE_OK 1
#define RANGE_NOT_OK 0

int batteryIsOk(float temperature, float soc, float chargeRate) {  
int TR,SR,CR;
    TR = Temp_Range(temperature);
    SR = State_Range(soc);
    CR = Charge_Range(chargeRate);
    if ( TR && SR && CR){
    return RANGE_OK;
    }
  return RANGE_NOT_OK;
}
int Temp_Range(float temperature)
{
    if(temperature <= 0 || temperature >= 45) {
        printf("Temperature out of range! for %f\n",temperature);
    return RANGE_NOT_OK; 
    }
    return RANGE_OK;
}
int State_Range(float soc)
{
    if(soc <= 20 || soc >= 80) {
        printf("State of Charge out of range! for %f\n",soc);
    return RANGE_NOT_OK;
    }
    return RANGE_OK;
}
int Charge_Range(float chargeRate)
{
    if (chargeRate<=0 || chargeRate >= 0.8) {
        printf("Charge Rate out of range! for %f\n",chargeRate);
    return RANGE_NOT_OK;
    }
    return RANGE_OK;
}
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
