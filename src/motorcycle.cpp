#include "motorcycle.h"
using  namespace std;

Motorcycle::Motorcycle(const string &id, const string &plate) : Vehicle(id, plate){}

SpotSize Motorcycle::getRequiredSpotSize() const {
    return SpotSize::Small;
}
