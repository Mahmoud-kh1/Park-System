#pragma once
#include "vehicle.h"
#include <string>
#include <optional>
using namespace std;
class ParkingSpot {
    std::string spotId_;
    SpotSize size_;
    bool occupied_ = false;
    optional<string> ticketId_;
public:
    ParkingSpot() = default;
    ParkingSpot(const string& id, SpotSize size);

    bool isFree() const;
    SpotSize getSize() const;
    void assign(const string& ticketId);
    void release();
    string getId() const;
    optional<string> ticketId() const;
};
