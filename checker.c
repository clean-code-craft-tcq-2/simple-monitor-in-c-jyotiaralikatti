#include <stdio.h>
#include<stdbool.h>
#include <assert.h>

int Temp_OTR(float );
int State_OTR(float );
int Charge_OTR(float );

int batteryIsOk(float temperature, float soc, float chargeRate) {    
    Temp_OTR(temperature);
    State_OTR(soc);
    Charge_OTR(chargeRate);
    
  return 1;
}
int Temp_OTR(float temperature)
{
    if(temperature < 0 || temperature > 45) 
        printf("Temperature out of range!\n");
    return 0;   
}
int State_OTR(float soc)
{
    if(soc < 20 || soc > 80) 
        printf("State of Charge out of range!\n");
    return 0;
}
int Charge_OTR(float chargeRate)
{
    if (chargeRate > 0.8) 
        printf("Charge Rate out of range!\n");
    return 0;
}
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
