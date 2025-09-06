#include "parkinglot.h"
#include <sstream>
#include <iostream>
#include <ctime>
using namespace  std;


void ParkingLot::addSpot(const ParkingSpot& spot) {
    spots_.push_back(spot);
}

int ParkingLot::findBestSpotFor(SpotSize required) const {
    int best = -1;
    for (size_t i = 0; i < spots_.size(); ++i) {
        if (!spots_[i].isFree()) continue;
        SpotSize s = spots_[i].getSize();
        bool fits = false;
        if (required == SpotSize::Small) {
            fits = (s == SpotSize::Small) || (s == SpotSize::Medium) || (s == SpotSize::Large);
        } else if (required == SpotSize::Medium) {
            fits = (s == SpotSize::Medium) || (s == SpotSize::Large);
        } else if (required == SpotSize::Large) {
            fits = (s == SpotSize::Large);
        }
        if (!fits) continue;
        if (best == -1) best = (int)i;
        else {
            SpotSize bestSize = spots_[best].getSize();
            if ((int)s < (int)bestSize) best = (int)i;
        }
    }
    return best;
}

string ParkingLot::makeTicketId() {
    ostringstream ss;
    ss << "T" << nextTicketCounter_++;
    return ss.str();
}

string ParkingLot::parkVehicle(const Vehicle& vehicle) {
    if (vehicleToTicket_.count(vehicle.getId())) {
        throw ParkingException("Vehicle already parked (open ticket exists).");
    }
    SpotSize required = vehicle.getRequiredSpotSize();
    int idx = findBestSpotFor(required);
    if (idx == -1) {
        throw ParkingException("No suitable parking spot available for this vehicle.");
    }
    string ticketId = makeTicketId();

    spots_[idx].assign(ticketId);

    Ticket t(ticketId, vehicle.getId(), spots_[idx].getId());
    tickets_.emplace(ticketId, t);
    vehicleToTicket_.emplace(vehicle.getId(), ticketId);
    return ticketId;
}

void ParkingLot::leaveVehicle(const string& ticketId) {
    auto it = tickets_.find(ticketId);
    if (it == tickets_.end()) throw ParkingException("Ticket not found.");
    Ticket &t = it->second;
    if (!t.isOpen()) throw ParkingException("Ticket already closed.");
    string spotId = t.getSpotId();
    bool found = false;
    for (auto &s : spots_) {
        if (s.getId() == spotId) {
            s.release();
            found = true;
            break;
        }
    }
    if (!found) throw ParkingException("Associated spot not found.");
    t.close(time(nullptr));
    vehicleToTicket_.erase(t.getVehicleId());
}

optional<string> ParkingLot::findVehicleTicket(const string& vehicleId) const {
    auto it = vehicleToTicket_.find(vehicleId);
    if (it == vehicleToTicket_.end()) return nullopt;
    return it->second;
}

vector<string> ParkingLot::listAvailableSpots() const {
    vector<string> res;
    for (const auto &s : spots_) {
        if (s.isFree()) res.push_back(s.getId());
    }
    return res;
}

void ParkingLot::printStatus() const {
    cout << "--- Parking Lot Status ---\n";
    cout << "Spots:\n";
    for (const auto &s : spots_) {
        cout << "  " << s.getId() << " [";
        SpotSize sz = s.getSize();
        if (sz == SpotSize::Small) cout << "Small";
        else if (sz == SpotSize::Medium) cout << "Medium";
        else cout << "Large";
        cout << "] : " << (s.isFree() ? "Free" : "Occupied") ;
        if (!s.isFree()) {
            auto tid = s.ticketId();
            if (tid.has_value()) cout << " (ticket=" << tid.value() << ")";
        }
        cout << "\n";
    }
    cout << "Tickets:\n";
    for (const auto &p : tickets_) {
        const Ticket &t = p.second;
        cout << "  " << t.getId() << " vehicle=" << t.getVehicleId() << " spot=" << t.getSpotId();
        if (t.isOpen()) cout << " (open)\n"; else cout << " (closed)\n";
    }
    cout << "---------------------------\n";
}
