#pragma once
#include "vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& id, const std::string& plate);
    SpotSize getRequiredSpotSize() const override;
};
