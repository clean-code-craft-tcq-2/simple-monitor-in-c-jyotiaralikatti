#include <stdbool.h>

#define BATTERYPARAMETER_TEMPERATURE 0
#define BATTERYPARAMETER_SOC 1
#define BATTERYPARAMETER_CHARGERATE 2

#define RANGE_OK 1
#define RANGE_NOT_OK 0

#define TEMPERATURE_MIN 0
#define TEMPERATURE_MAX 45

#define SOC_MIN 20
#define SOC_MAX 80

#define CHARGERATE_MAX 0.8

#define TOLERANCE_LOWERLIMIT_APPROACHED 0
#define TOLERANCE_HIGHERLIMIT_APPROACHED 1

#define TOLERANCE_PERCENTILE 5

#define UNUSED(x) (void)(x)

bool IsSOCValid(float );
bool State_Range(float );

bool IsChargeRateValid(float );
bool Charge_Rate(float );

bool IsTemperatureValid(float );
bool Temp_Range(float );


bool CheckForEarlyWarning(int , float );

