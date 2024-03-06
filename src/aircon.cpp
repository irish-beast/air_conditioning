#include <cassert>
#include "airconmain.h"

void AirConditioningApplication::SelectThreshold(uint32_t temperature) {
  threshold = temperature;
}

void AirConditioningApplication::TemperatureMeasurement(uint32_t temperature) {
  accumulated += temperature;
  count++;
}

void AirConditioningApplication::MeasurementTick() {
  /* count could be 0 if MeasurementTick called before TemperatureMeasurement()
  and we don't want /0 exception. We assume this only happens once and 
  TemperatureMeasurement() is called regularly */
  
  assert(threshold > 0);
  
  if (count != 0) {
    auto temp = accumulated / count;
    if (aircon_on) {
      if (temp < threshold - hysteresis) { 
        SwitchOff();
        aircon_on = false;
        }
      }
    else {
      if (temp > threshold + hysteresis) { 
        SwitchOn();
        aircon_on = true;
      }
    }
  } // if count
  accumulated = 0;
  count = 0;
}


