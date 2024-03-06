#include <cstdint>

using namespace std;

/* All temperatures are in milli Kelvin. 
So freezing is about 273150 boiling 373150
1/1000 degree is accurate enough, and never negative so we don't have to worry 
about negatives. Anywhere on the planet (or off planet) 
*/

const uint32_t multiplier = 1000;
const uint32_t zero_degrees = 273150;

