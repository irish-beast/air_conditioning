#include <cstdint>
#include "airconapi.h"

using namespace std;

class AirConditioningApplication: public AirConditioningAPI {
  private:
    bool     aircon_on;
    uint32_t accumulated;
    uint32_t hysteresis;
    uint16_t count;
    
  // All temperatures are in milli Kelvin.
  public:
    AirConditioningApplication(uint32_t hysteresis) :
      aircon_on(false),
      count(0), 
      accumulated(0), 
      hysteresis(hysteresis) {}
    // constructor accepts hysteresis because we don't expect this to change

    void SelectThreshold(uint32_t temperature);
    // Program threshold at which we switch on/off subject to hysterisis
    
    void TemperatureMeasurement(uint32_t temperature);
    // Called "regularly" with current temperature in milli Kelvin
    
    void MeasurementTick();
    // Called every interval (1 second). Averages out temperature and 
    // makes on/off decision
};


