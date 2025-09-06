#pragma once
#include "vehicle.h"
using namespace std;
class Motorcycle : public Vehicle {
public:
    Motorcycle(const string& id, const string& plate);
    SpotSize getRequiredSpotSize() const override;
};
