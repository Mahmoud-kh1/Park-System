#pragma once
#include "vehicle.h"
using  namespace std;
class Car : public Vehicle {
public:

    Car(const string& id, const string& plate);

    SpotSize getRequiredSpotSize() const override;
};

