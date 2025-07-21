#pragma once
#include <vector>
#include <string>
#include "Car.h"

class Service {
private:
    std::vector<Car*> cars;
public:
    // add a car 
    void addCar(Car* car);

    // get all cars
    std::vector<Car*> getAllCars() const;

    // save cars cheaper than a price
    void saveCarsCheaperThan(double maxPrice, const std::string& filename) const;

    // destructor
    ~Service();
};
