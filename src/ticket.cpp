#include "ticket.h"

Ticket::Ticket(const std::string& ticketId, const std::string& vehicleId, const std::string& spotId)
        : ticketId_(ticketId), vehicleId_(vehicleId), spotId_(spotId), entryTime_(std::time(nullptr)) {}

void Ticket::close(time_t exitTime) {
    exitTime_ = exitTime;
}
bool Ticket::isOpen() const { return !exitTime_.has_value(); }

string Ticket::getId() const { return ticketId_; }

string Ticket::getVehicleId() const { return vehicleId_; }

string Ticket::getSpotId() const { return spotId_; }

time_t Ticket::getEntryTime() const { return entryTime_; }

optional<time_t> Ticket::getExitTime() const { return exitTime_; }
