#include "DishWasher.h"
#include <sstream>

DishWasher::DishWasher(const std::string& id, double electricityForOneHour)
    : Appliance(id), consumedElectricityForOneHour(electricityForOneHour) {}

double DishWasher::consumedElectricity() const {
    return consumedElectricityForOneHour * 20;
}

std::string DishWasher::toString() const {
    std::ostringstream stream;
    stream << "DishWasher ID: " << getId() << ", Consumed Electricity for One Hour: "
        << consumedElectricityForOneHour << " KW, Monthly Consumption: "
        << consumedElectricity() << " KW";
    return stream.str();
}
