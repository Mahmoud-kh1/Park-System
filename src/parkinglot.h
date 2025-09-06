#pragma once
#include "parkingspot.h"
#include "ticket.h"
#include "vehicle.h"
#include "exceptions.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <optional>



class ParkingLot {
    std::vector<ParkingSpot> spots_;
    std::unordered_map<std::string, Ticket> tickets_; // ticketId -> Ticket
    std::unordered_map<std::string, std::string> vehicleToTicket_; // vehicleId -> ticketId
    int nextTicketCounter_ = 1;
public:
    ParkingLot() = default;
    void addSpot(const ParkingSpot& spot);
    std::string parkVehicle(const Vehicle& vehicle);
    void leaveVehicle(const std::string& ticketId);
    std::optional<std::string> findVehicleTicket(const std::string& vehicleId) const;
    std::vector<std::string> listAvailableSpots() const;
    void printStatus() const;
private:
    int findBestSpotFor(SpotSize required) const;
    std::string makeTicketId();
};
