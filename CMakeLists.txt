cmake_minimum_required(VERSION 3.10)
project(ParkingLotOOP_TODO)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(parking_lot
    src/main.cpp
    src/vehicle.cpp
    src/car.cpp
    src/motorcycle.cpp
    src/truck.cpp
    src/parkingspot.cpp
    src/ticket.cpp
    src/parkinglot.cpp
    src/exceptions.cpp
)
