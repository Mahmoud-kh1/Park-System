#include "car.h"
using namespace  std;

Car::Car(const string &id , const string & plate) : Vehicle(id, plate){}

SpotSize Car::getRequiredSpotSize() const {
    return SpotSize::Medium;
}




