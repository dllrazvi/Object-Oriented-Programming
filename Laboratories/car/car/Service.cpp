#include "Service.h"
#include <fstream>
#include <algorithm>

// add a car
void Service::addCar(Car* car) {
    cars.push_back(car);
}

// set all cars
std::vector<Car*> Service::getAllCars() const {
    return cars;
}

// save cars cheaper than a price
void Service::saveCarsCheaperThan(double maxPrice, const std::string& filename) const {
    std::vector<Car*> filtered;
    //search cars by price
    for (auto car : cars) {
        if (car->getPrice() < maxPrice) {
            filtered.push_back(car);
        }
    }
    //sort cars by price
    std::sort(filtered.begin(), filtered.end(), [](Car* c1, Car* c2) {
        return c1->getPrice() < c2->getPrice();
        });
    //write cars tothe file
    std::ofstream fout(filename);
    for (auto car : filtered) {
        fout << car->toString() << "\n";
    }
    fout.close();
}

// destructor
Service::~Service() {
    for (auto car : cars) {
        delete car;
    }
}
