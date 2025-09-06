#include <iostream>
#include "parkinglot.h"
#include "car.h"
#include "motorcycle.h"
#include "truck.h"
#include <memory>
using namespace std;
int main() {
    ParkingLot lot;
    // setup: add some spots
    lot.addSpot(ParkingSpot("S1", SpotSize::Small));
    lot.addSpot(ParkingSpot("S2", SpotSize::Small));
    lot.addSpot(ParkingSpot("M1", SpotSize::Medium));
    lot.addSpot(ParkingSpot("M2", SpotSize::Medium));
    lot.addSpot(ParkingSpot("L1", SpotSize::Large));

    bool running = true;
    while (running) {
        cout << "\nParking Lot Menu:\n";
        cout << "1) Park Car\n2) Park Motorcycle\3) Park Truck\n4) Leave (ticket id)\n5) Status\n0) Exit\"\n";
        cout << "Choose: ";
        int choice;
        if (!(cin >> choice)) break;
        try {
            if (choice == 0) running = false;
            else if (choice == 1) {
                string id, plate;
                cout << "Enter vehicle id: "; cin >> id;
                cout << "Enter plate: "; cin >> plate;
                Car c(id, plate);
                string tid = lot.parkVehicle(c);
                cout << "Parked. Ticket: " << tid << "\n";
            } else if (choice == 2) {
                string id, plate;
                cout << "Enter vehicle id: "; cin >> id;
                cout << "Enter plate: "; cin >> plate;
                Motorcycle m(id, plate);
                string tid = lot.parkVehicle(m);
                cout << "Parked. Ticket: " << tid << "\n";
            } else if (choice == 3) {
                string id, plate;
                cout << "Enter vehicle id: "; cin >> id;
                cout << "Enter plate: "; cin >> plate;
                Truck t(id, plate);
                string tid = lot.parkVehicle(t);
                cout << "Parked. Ticket: " << tid << "\n";
            } else if (choice == 4) {
                string tid;
                cout << "Enter ticket id: "; cin >> tid;
                lot.leaveVehicle(tid);
                cout << "Vehicle left.\n";
            } else if (choice == 5) {
                lot.printStatus();
            } else {
                cout << "Invalid choice\n";
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
