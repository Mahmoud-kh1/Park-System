#pragma once
#include <string>
#include <ctime>
#include <optional>
using  namespace  std;

class Ticket {
    string ticketId_;
    string vehicleId_;
    string spotId_;
    time_t entryTime_;
    optional<time_t> exitTime_;
public:
    Ticket(const string& ticketId, const string& vehicleId, const string& spotId);
    void close(time_t exitTime);
    bool isOpen() const;
    string getId() const;
    string getVehicleId() const;
    string getSpotId() const;
    time_t getEntryTime() const;
    optional<time_t> getExitTime() const;
};
