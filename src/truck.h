#pragma once
#include "vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const std::string& id, const std::string& plate);
    SpotSize getRequiredSpotSize() const override;
};
