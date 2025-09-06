#pragma once
#include <string>
using  namespace std;
enum class SpotSize { Small, Medium, Large };

class Vehicle {
protected:
    std::string id_;
    std::string licensePlate_;
public:

    Vehicle(const string& id, const string& plate);
    virtual ~Vehicle() = default;

    string getId() const;
    string getLicensePlate() const;

    virtual SpotSize getRequiredSpotSize() const = 0;
};
