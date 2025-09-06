#include "parkingspot.h"
using namespace std;
ParkingSpot::ParkingSpot(const string& id, SpotSize size)
        : spotId_(id), size_(size), occupied_(false) {}

bool ParkingSpot::isFree() const { return !occupied_; }

SpotSize ParkingSpot::getSize() const { return size_; }

void ParkingSpot::assign(const string& ticketId) {
    occupied_ = true;
    ticketId_ = ticketId;
}

void ParkingSpot::release() {
    occupied_ = false;
    ticketId_.reset();
}
string ParkingSpot::getId() const { return spotId_; }

optional<string> ParkingSpot::ticketId() const { return ticketId_; }
