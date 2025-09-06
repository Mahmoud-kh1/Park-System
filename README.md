# Park-System System (C++ OOP Project)

This is a simple **Object-Oriented Programming project** in C++ that simulates a parking lot system.  
It’s designed to practice and demonstrate OOP concepts like **classes, inheritance, polymorphism, encapsulation, and composition**.

---

## UML Diagram

![UML Diagram](https://github.com/Mahmoud-kh1/Park-System/blob/main/images/Screenshot%202025-09-06%20122759.png?raw=true) 
## Features
- Vehicles: `Car`, `Motorcycle`, `Truck` (all inherit from `Vehicle`)
- `ParkingSpot`: tracks size and if it’s occupied
- `Ticket`: records entry/exit times
- `ParkingLot`: manages spots, tickets, and vehicles
---

## How to Build & Run

```bash
# Go to project directory
cd src

# Compile
g++ *.cpp -o parkinglot

# Run
./parkinglot
