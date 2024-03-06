#include "airconapp.h"

class AirConditioningMain: public AirConditioningApplication {
  // Implements virtual from AirConditioningAPI
  public:
    using AirConditioningApplication::AirConditioningApplication;
    void SwitchOn();
    void SwitchOff();
};


