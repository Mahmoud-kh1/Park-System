#include "motorcycle.h"


Motorcycle::Motorcycle(const std::string &id, const std::string &plate) : Vehicle(id, plate){}

SpotSize Motorcycle::getRequiredSpotSize() const {
    return SpotSize::Small;
}
