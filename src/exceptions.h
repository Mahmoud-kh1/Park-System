#pragma once
#include <stdexcept>
#include <string>

class ParkingException : public std::runtime_error {
public:
    explicit ParkingException(const std::string& msg) : std::runtime_error(msg) {}
};
