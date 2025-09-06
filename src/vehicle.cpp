#include "vehicle.h"
using namespace  std;
Vehicle::Vehicle(const std::string& id, const std::string& plate)
        : id_(id), licensePlate_(plate) {}

string Vehicle::getId() const { return id_; }

string Vehicle::getLicensePlate() const { return licensePlate_; }

