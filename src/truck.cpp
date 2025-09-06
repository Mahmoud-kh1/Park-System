#include "truck.h"

Truck::Truck(const std::string &id, const std::string &plate) : Vehicle(id, plate){}

SpotSize Truck::getRequiredSpotSize() const {
    return SpotSize::Large;
}

