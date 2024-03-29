#include <gtest/gtest.h>
#include <iostream>
#include "airconmain.h"

using namespace std;

const bool doprint = false;

void AirConditioningMain::SwitchOn() {
  if (doprint)
    cout << "Switching on"; 
}

void AirConditioningMain::SwitchOff() {
  if (doprint)
    cout << "Switching off"; 
}


TEST(AirconTest, AssertFail) {
  auto aircon = new AirConditioningMain(500);
  ASSERT_DEATH(aircon->MeasurementTick(), ".*");
}


TEST(AirconTest, BasicOperation) {
  auto aircon = new AirConditioningMain(500); // Temperature has to change 1C to switch
  aircon->SelectThreshold(20000); // 20C
  
  // Bring to about 22C
  for (auto i=0; i<100; i++)
    aircon->TemperatureMeasurement(22000+i);
  aircon->MeasurementTick();
  ASSERT_TRUE(aircon->aircon_on);
  
  // Bring to about 19.7C
  for (auto i=0; i<100; i++)
    aircon->TemperatureMeasurement(19700+i);
  aircon->MeasurementTick();
  ASSERT_TRUE(aircon->aircon_on);
  
  // Bring to about 19C
  for (auto i=0; i<100; i++)
    aircon->TemperatureMeasurement(19000+i);
  aircon->MeasurementTick();
  ASSERT_FALSE(aircon->aircon_on);

  // Verify no divide by 0 error
  ASSERT_EQ(aircon->count, 0);
  aircon->MeasurementTick();

}
