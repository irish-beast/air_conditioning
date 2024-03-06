#include <iostream>
#include "airconmain.h"
using namespace std;

void AirConditioningMain::SwitchOn() {
  cout << "Switching on"; }

void AirConditioningMain::SwitchOff() {
  cout << "Switching off"; }

int main(void) {
  auto aircon = new AirConditioningMain(500); // hysterisis is 0.5C
}
